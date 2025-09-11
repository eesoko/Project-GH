% =========================================================================
% [ SCRIPT ]    : feature_extractor_elite.m
% [ VERSION ]   : 2.0
% [ AUTHOR ]    : GeunHwang Project
% [ DATE ]      : 2025-09-11
%
% [ OVERVIEW ]
%   '손목의 물리' 원칙에 기반하여, 운동의 본질을 설명하는 24개의
%   핵심 정예 특징(Elite Features)만을 추출하는 스크립트입니다.
% =========================================================================

clear; clc;

%% --- 1. 경로 설정 및 폴더 선택 ---
[current_script_path, ~, ~] = fileparts(mfilename('fullpath'));
output_folder = fullfile(current_script_path, '..', '01_data', 'processed');
input_folder = uigetdir(current_script_path, 'Select the folder containing CSV files');
if isequal(input_folder, 0), disp('User selected Cancel'); return; end

%% --- 2. 파일 스캔 및 테이블 초기화 ---
csv_files = dir(fullfile(input_folder, '*.csv'));
if isempty(csv_files), disp('No CSV files found.'); return; end
feature_table = table();
fprintf('Starting Elite Feature extraction for %d files...\n', length(csv_files));

%% --- 3. 특징 추출 메인 루프 ---
for i = 1:length(csv_files)
    file_name = csv_files(i).name;
    full_path = fullfile(input_folder, file_name);
    fprintf('  - Processing (%d/%d): %s\n', i, length(csv_files), file_name);
    
    try
        data_table = readtable(full_path);
        
        % --- 물리량 정의 ---
        ax = data_table.ax; ay = data_table.ay; az = data_table.az;
        gx = data_table.gx; gy = data_table.gy; gz = data_table.gz;
        Fs = 50; % 샘플링 주파수
        
        % ==================== 💎 정예 특징 계산 💎 ====================

        % --- 기둥 1: 자세 (Orientation) - 6개 ---
        % 물리적 의미: 손목의 평균적인 기울기와 그 변화량
        f1_mean_ax = mean(ax); f1_mean_ay = mean(ay); f1_mean_az = mean(az);
        f1_std_ax = std(ax);   f1_std_ay = std(ay);   f1_std_az = std(az);
        
        % --- 기둥 2: 궤적 (Trajectory) - 5개 ---
        % 물리적 의미: 손목의 회전량과 움직임의 모양
        f2_rms_gx = rms(gx); f2_rms_gy = rms(gy); f2_rms_gz = rms(gz);
        f2_corr_ax_ay = corr(ax, ay); % 수직면(덤벨 컬) 궤적
        f2_corr_ay_gz = corr(ay, gz); % 수평면(사레레) 궤적
        
        % --- 기둥 3: 주기와 강도 (Periodicity & Intensity) - 5개 ---
        % 물리적 의미: 운동의 속도(리듬)와 손목 움직임의 격렬함
        accel_mag = sqrt(ax.^2 + ay.^2 + az.^2); % 가속도 총량
        f3_rms_accel_mag = rms(accel_mag);
        f3_range_accel_mag = max(accel_mag) - min(accel_mag);
        
        gyro_mag = sqrt(gx.^2 + gy.^2 + gz.^2); % 각속도 총량
        f3_rms_gyro_mag = rms(gyro_mag);
        
        [P, f] = periodogram(accel_mag, [], [], Fs);
        [~, loc] = max(P);
        f3_dom_freq_accel = f(loc); % 가속도 리듬
        
        [P, f] = periodogram(gyro_mag, [], [], Fs);
        [~, loc] = max(P);
        f3_dom_freq_gyro = f(loc); % 각속도 리듬
        
        % --- 숨겨진 보석: 운동의 질 (Quality) - 4개 ---
        % 물리적 의미: 움직임의 부드러움과 총량
        jerk_x = diff(ax); jerk_y = diff(ay); jerk_z = diff(az);
        jerk_mag = sqrt(jerk_x.^2 + jerk_y.^2 + jerk_z.^2);
        f4_mean_jerk_mag = mean(jerk_mag); % 저크(부드러움)
        f4_std_jerk_mag = std(jerk_mag);
        
        f4_sma_accel = mean(abs(ax) + abs(ay) + abs(az)); % 가속도 총량
        f4_sma_gyro = mean(abs(gx) + abs(gy) + abs(gz)); % 각속도 총량
        
        % =============================================================
        
        % --- 결과 테이블 생성 ---
        feature_row = [ ...
            f1_mean_ax, f1_mean_ay, f1_mean_az, f1_std_ax, f1_std_ay, f1_std_az, ...
            f2_rms_gx, f2_rms_gy, f2_rms_gz, f2_corr_ax_ay, f2_corr_ay_gz, ...
            f3_rms_accel_mag, f3_range_accel_mag, f3_rms_gyro_mag, f3_dom_freq_accel, f3_dom_freq_gyro, ...
            f4_mean_jerk_mag, f4_std_jerk_mag, f4_sma_accel, f4_sma_gyro ...
        ];
        
        var_names = { ...
            'mean_ax', 'mean_ay', 'mean_az', 'std_ax', 'std_ay', 'std_az', ...
            'rms_gx', 'rms_gy', 'rms_gz', 'corr_ax_ay', 'corr_ay_gz', ...
            'rms_accel_mag', 'range_accel_mag', 'rms_gyro_mag', 'dom_freq_accel', 'dom_freq_gyro', ...
            'mean_jerk_mag', 'std_jerk_mag', 'sma_accel', 'sma_gyro' ...
        };
        
        temp_table = array2table(feature_row, 'VariableNames', var_names);
        name_parts = split(file_name, '_');
        temp_table.exerciseName = string(name_parts{1});
        
        feature_table = [feature_table; temp_table];
        
    catch ME
        fprintf('Could not process file: %s. Error: %s\n', file_name, ME.message);
    end
end

%% --- 4. 결과 저장 ---
if ~isempty(feature_table)
    timestamp = datestr(now, 'yyyy-mm-dd_HHMMSS');
    output_filename = ['feature_table_elite_', timestamp, '.csv'];
    output_path = fullfile(output_folder, output_filename);
    writetable(feature_table, output_path);
    
    fprintf('\n>> Elite feature extraction complete!\n');
    fprintf('>> Features saved to:\n   %s\n', output_path);
else
    disp('No data was processed.');
end
