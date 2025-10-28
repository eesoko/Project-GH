% --- 1. 훈련된 모델 로드 ---
% 'myEnsembleModel_v2.mat' 파일을 불러옵니다.
fprintf('1. 모델 파일 로드 중... (mySVMModel.mat)\n');
model_data = load('../03_models/mySVMModel.mat');

% --- 2. 실제 모델 객체 추출 ---
top_variable_name = 'mySVMModel'
actual_model_object = model_data.(top_variable_name).ClassificationSVM;
fprintf('  > 모델 객체 추출 완료.\n');

% --- 3. 모델 입력 크기 정의 ---
% 우리 특징 추출기(FeatureExtractor)의 출력은 [1, 32] 벡터입니다.
input_size = [1, 32];
fprintf('  > 모델 입력 크기: [1, 32]\n');

% --- 4. ONNX로 내보내기 ---
% 'model.onnx' 라는 이름의 파일이 생성됩니다.
output_filename = 'model.onnx';
exportONNX(actual_model_object, output_filename, 'InputSize', input_size);

fprintf('\n*** %s 파일 생성 완료! ***\n', output_filename);