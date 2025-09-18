% =========================================================================
% [ SCRIPT ]    : generate_cpp.m (설계도 기반 최종 버전)
% [ OVERVIEW ]
%   mySVMModel.mat의 정확한 내부 구조를 기반으로 모든 파라미터를 추출하고,
%   predict_manual_svm.m 스크립트를 C++로 변환합니다.
% =========================================================================

disp('>> 최종 빌드 자동화 스크립트를 시작합니다...');

%% --- 1단계: 모델 분석 및 파라미터 추출 ---
original_model_name = 'mySVMModel.mat';
original_model_path = fullfile('..', '03_models', original_model_name);
android_project_path = 'C:\Users\dltjr\OneDrive\Desktop\git\Project-GH'; % 안드로이드 프로젝트 경로

disp(['>> 원본 모델: ', original_model_path, ' 를 분석합니다.']);
s = load(original_model_path);
model_struct = s.mySVMModel; % 최상위 구조체
model_object = model_struct.ClassificationSVM; % 실제 모델 객체

% --- 설계도에 명시된 정확한 경로에서 모든 파라미터를 추출 ---
disp('   - 모델 파라미터 추출 중...');
% 1. BinaryLearners (Beta, Bias)
binary_learners = model_object.BinaryLearners;
num_learners = numel(binary_learners);
if num_learners == 0
    error('모델에 바이너리 학습기가 없습니다.');
end
num_features = size(binary_learners{1}.Beta, 1);
all_betas = zeros(num_features, num_learners);
all_biases = zeros(1, num_learners);
for i = 1:num_learners
    all_betas(:, i) = binary_learners{i}.Beta;
    all_biases(i) = binary_learners{i}.Bias;
end

% 2. 기타 필수 파라미터
required_vars = model_struct.RequiredVariables;
coding_matrix = model_object.CodingMatrix;
class_names = model_object.ClassNames;
disp('   - 파라미터 추출 완료.');

%% --- 2단계: C++ 코드 생성 ---
cfg = coder.config('lib');
cfg.TargetLang = 'C++';
cfg.GenerateReport = false;
codegen_folder = fullfile(pwd, 'codegen_temp');

% C++ 변환 대상 함수에 전달할 인자 정의
sensor_data_type = coder.typeof(0, [inf, 6]);
codegen_args = {sensor_data_type, coder.Constant(all_betas), coder.Constant(all_biases), ...
                coder.Constant(coding_matrix), coder.Constant(required_vars), coder.Constant(class_names)};

disp('>> Codegen을 실행하여 predict_manual_svm.m을 C++로 변환합니다...');
codegen predict_manual_svm -config cfg -args codegen_args -d codegen_folder;
disp('>> Codegen 실행 완료.');

%% --- 3단계: 파일 복사 및 정리 ---
output_folder = fullfile(android_project_path, 'app', 'src', 'main', 'cpp');
source_folder = fullfile(codegen_folder, 'lib', 'predict_manual_svm');

if isfolder(source_folder)
    copyfile(fullfile(source_folder, '*.cpp'), output_folder);
    copyfile(fullfile(source_folder, '*.h'), output_folder);
    disp('>> 모든 C++ 파일이 성공적으로 안드로이드 프로젝트에 복사되었습니다.');
    rmdir(codegen_folder, 's');
    disp('>> 빌드 자동화 스크립트가 성공적으로 완료되었습니다. ✨');
else
    disp('>> [오류] C++ 파일이 생성되지 않았거나 소스 폴더를 찾을 수 없습니다.');
end