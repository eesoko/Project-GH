% feature_extractor_advanced.m - '근황' 앱을 위한 다차원 특징 추출 스크립트

clear; close all; clc;

% --- 1. 사용자에게 데이터 폴더 선택 ---
folderName = uigetdir('', 'Select the folder containing CSV files');
if isequal(folderName, 0), disp('User selected Cancel'); return; end
disp(['Selected folder: ', folderName]);

% --- 2. 폴더 내 CSV 파일 목록 가져오기 ---
csvFiles = dir(fullfile(folderName, '*.csv'));
if isempty(csvFiles), disp('No CSV files found.'); return; end

% --- 3. 최종 특징 테이블 초기화 ---
featureTable = table();
% 센서 채널 이름 정의 (결과 테이블의 변수명으로 사용)
sensorNames = {'ax', 'ay', 'az', 'gx', 'gy', 'gz'};

fprintf('\nStarting advanced feature extraction for %d files...\n', length(csvFiles));

% --- 4. 각 CSV 파일에 대해 반복 작업 ---
for i = 1:length(csvFiles)
    fileName = csvFiles(i).name;
    fullPath = fullfile(folderName, fileName);
    fprintf('Processing (%d/%d): %s\n', i, length(csvFiles), fileName);
    
    try
        dataTable = readtable(fullPath);
        sensorData = [dataTable.ax, dataTable.ay, dataTable.az, ...
                      dataTable.gx, dataTable.gy, dataTable.gz];
        
        % --- 4-1. 기본 통계 특징 (30개) ---
        f_mean = mean(sensorData);
        f_std = std(sensorData);
        f_max = max(sensorData);
        f_min = min(sensorData);
        f_rms = rms(sensorData);
        
        % --- 4-2. 시간 영역 추가 특징 (12개) ---
        f_zcr = mean(abs(diff(sign(sensorData)))); % Zero-Crossing Rate
        f_ssc = mean(abs(diff(sign(diff(sensorData))))); % Slope Sign Change
        
        % --- 4-3. 주파수 영역 특징 (FFT 기반, 12개) ---
        Fs = 50; % 샘플링 주파수 (Hz), 1초에 50개 데이터 기준
        N = length(sensorData);
        f_dom_freq = zeros(1, 6);
        f_spec_energy = zeros(1, 6);
        
        for ch = 1:6
            Y = fft(sensorData(:, ch));
            P2 = abs(Y/N);
            P1 = P2(1:N/2+1);
            P1(2:end-1) = 2*P1(2:end-1);
            f = Fs*(0:(N/2))/N;
            
            [~, idx] = max(P1);
            f_dom_freq(ch) = f(idx); % 주요 주파수
            f_spec_energy(ch) = sum(P1.^2) / length(P1); % 스펙트럼 에너지
        end
        
        % --- 4-4. 센서 간 상관관계 특징 (선별 5개) ---
        corr_ay_gx = corr(dataTable.ay, dataTable.gx);
        corr_az_gy = corr(dataTable.az, dataTable.gy);
        corr_ax_gz = corr(dataTable.ax, dataTable.gz);
        corr_ax_ay = corr(dataTable.ax, dataTable.ay);
        corr_gx_gy = corr(dataTable.gx, dataTable.gy);
        
        % --- 4-5. 모든 특징을 하나의 행으로 결합 ---
        featureRowValues = [f_mean, f_std, f_max, f_min, f_rms, f_zcr, f_ssc, ...
                            f_dom_freq, f_spec_energy, ...
                            corr_ay_gx, corr_az_gy, corr_ax_gz, corr_ax_ay, corr_gx_gy];
                        
        tempTable = array2table(featureRowValues);
        
        % --- 4-6. 정답 라벨 추가 ---
        nameParts = split(fileName, '_');
        tempTable.exerciseName = string(nameParts{1});
        
        featureTable = [featureTable; tempTable];
        
    catch ME
        fprintf('Could not process file: %s. Error: %s\n', fileName, ME.message);
    end
end

% --- 5. 최종 결과 저장 ---
if ~isempty(featureTable)
    outputFileName = 'feature_table_advanced.csv';
    writetable(featureTable, outputFileName);

    disp('------------------------------------');
    disp('Advanced feature extraction complete!');
    disp(['Features saved to: ', outputFileName]);
    disp('Ready for the Classification Learner app.');
    disp('------------------------------------');
else
    disp('No data was processed. Output file was not created.');
end