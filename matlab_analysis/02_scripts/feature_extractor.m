% feature_extractor.m - 지정 폴더 저장 및 시간 기록 기능만 적용

clear; clc;

% ==========================================================
% >> 저장될 위치 (고정 경로)
output_folder = 'C:\Users\SeokHoLee\Desktop\GIt\GH\matlab_analysis\01_data\processed';
% ==========================================================

% --- 1. 데이터 폴더 선택 ---
input_folder = uigetdir('', 'Select the folder containing CSV files');
if isequal(input_folder, 0), disp('User selected Cancel'); return; end

% --- 2. CSV 파일 목록 가져오기 ---
csv_files = dir(fullfile(input_folder, '*.csv'));
if isempty(csv_files), disp('No CSV files found.'); return; end

% --- 3. 특징 추출 ---
feature_table = table();
fprintf('Starting feature extraction for %d files...\n', length(csv_files));

for i = 1:length(csv_files)
    file_name = csv_files(i).name;
    full_path = fullfile(input_folder, file_name);
    fprintf('Processing: %s\n', file_name);
    
    try
        % (대표님의 핵심 특징 추출 로직은 그대로 유지됩니다)
        dataTable = readtable(full_path);
        sensorData = [dataTable.ax, dataTable.ay, dataTable.az, ...
                      dataTable.gx, dataTable.gy, dataTable.gz];
        
        f_mean = mean(sensorData); f_std = std(sensorData);
        f_max = max(sensorData); f_min = min(sensorData); f_rms = rms(sensorData);
        f_zcr = mean(abs(diff(sign(sensorData))));
        f_ssc = mean(abs(diff(sign(diff(sensorData)))));
        
        Fs = 50; N = length(sensorData);
        f_dom_freq = zeros(1, 6); f_spec_energy = zeros(1, 6);
        for ch = 1:6
            Y = fft(sensorData(:, ch)); P2 = abs(Y/N);
            P1 = P2(1:floor(N/2)+1); P1(2:end-1) = 2*P1(2:end-1);
            f = Fs*(0:(floor(N/2)))/N;
            [~, idx] = max(P1);
            f_dom_freq(ch) = f(idx);
            f_spec_energy(ch) = sum(P1.^2) / length(P1);
        end
        
        correlations = [corr(dataTable.ay, dataTable.gx), corr(dataTable.az, dataTable.gy), ...
                        corr(dataTable.ax, dataTable.gz), corr(dataTable.ax, dataTable.ay), ...
                        corr(dataTable.gx, dataTable.gy)];
                        
        featureRowValues = [f_mean, f_std, f_max, f_min, f_rms, f_zcr, f_ssc, ...
                            f_dom_freq, f_spec_energy, correlations];
                        
        tempTable = array2table(featureRowValues);
        
        sensorNames = {'ax', 'ay', 'az', 'gx', 'gy', 'gz'};
        statNames = {'_mean', '_std', '_max', '_min', '_rms', '_zcr', '_ssc', '_domFreq', '_specEnergy'};
        varNames = {};
        for s = 1:length(statNames)
            for ch = 1:length(sensorNames)
                varNames{end+1} = [sensorNames{ch}, statNames{s}];
            end
        end
        corrNames = {'corr_ay_gx', 'corr_az_gy', 'corr_ax_gz', 'corr_ax_ay', 'corr_gx_gy'};
        tempTable.Properties.VariableNames = [varNames, corrNames];
        
        nameParts = split(file_name, '_');
        tempTable.exerciseName = string(nameParts{1});
        
        feature_table = [feature_table; tempTable];
        
    catch ME
        fprintf('Could not process file: %s. Error: %s\n', file_name, ME.message);
    end
end

% --- 4. 결과 저장 ---
if ~isempty(feature_table)
    % 현재 시간을 이용해 파일명 생성
    timestamp = datestr(now, 'yyyy-mm-dd_HHMMSS');
    output_filename = ['feature_table_', timestamp, '.csv'];
    
    % 지정된 경로에 파일 저장
    output_path = fullfile(output_folder, output_filename);
    writetable(feature_table, output_path);
    
    fprintf('\n>> 작업 완료!\n');
    fprintf('>> 결과가 다음 경로에 저장되었습니다:\n   %s\n', output_path);
else
    disp('처리된 데이터가 없습니다.');
end