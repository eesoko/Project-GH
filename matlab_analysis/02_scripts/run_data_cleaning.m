% =========================================================================
% [ SCRIPT ]    : run_data_cleaning.m
% [ OVERVIEW ]  : 지정된 폴더의 모든 원본 CSV 파일을 읽어, Data Cleaner로
%                 생성한 'cleanData' 함수를 적용하고, 'cleaned' 폴더에
%                 결과를 자동으로 저장하는 마스터 스크립트입니다.
% =========================================================================

clear; clc;

%% --- 1. 경로 설정 및 폴더 선택 ---
[current_script_path, ~, ~] = fileparts(mfilename('fullpath'));

% 원본 데이터가 있는 폴더 선택
input_folder = uigetdir(current_script_path, 'Select the folder with RAW CSV files');
if isequal(input_folder, 0), disp('User selected Cancel'); return; end

% 깨끗해진 데이터를 저장할 새 폴더 생성
output_folder = fullfile(current_script_path, '..', '01_data', 'cleaned_data');
if ~exist(output_folder, 'dir')
   mkdir(output_folder);
end

%% --- 2. 파일 스캔 및 자동 클리닝 루프 ---
csv_files = dir(fullfile(input_folder, '*.csv'));
if isempty(csv_files), disp('No CSV files found.'); return; end
fprintf('Starting data cleaning for %d files...\n', length(csv_files));

for i = 1:length(csv_files)
    file_name = csv_files(i).name;
    full_input_path = fullfile(input_folder, file_name);
    full_output_path = fullfile(output_folder, file_name);
    
    fprintf('  - Cleaning (%d/%d): %s\n', i, length(csv_files), file_name);
    
    try
        % 1. 원본 데이터 읽기
        original_data = readtable(full_input_path);
        
        % 2. Data Cleaner가 생성한 함수 호출!
        cleaned_data = cleanData(original_data); 
        
        % 3. 깨끗해진 데이터를 새 파일로 저장
        writetable(cleaned_data, full_output_path);
        
    catch ME
        fprintf('Could not process file: %s. Error: %s\n', file_name, ME.message);
    end
end

fprintf('\n>> Data cleaning complete!\n');
fprintf('>> Cleaned files are saved in:\n   %s\n', output_folder);
