function predictedExercise = predictExercise(sensorData, codegen_model_path, feature_names)
%#codegen

% =========================================================================
% [ SCRIPT ]    : predictExercise.m (v8 - 범용 최종 버전)
% [ OVERVIEW ]
%   외부로부터 모델 경로와 '특징 이름 목록'을 인자로 받아,
%   모델의 종류에 상관없이 예측을 수행하는 범용 함수입니다.
% =========================================================================

persistent model;
if isempty(model)
    model_struct = coder.load(codegen_model_path);
    % Coder용 모델은 compactStruct 안에 실제 모델이 있습니다.
    model = model_struct.compactStruct;
end

% 1. 특징 추출 (결과는 1x32 double 배열)
features_array = feature_extractor_codegen(sensorData);

% 2. 전달받은 'feature_names'를 이용해 테이블 생성
features_table = array2table(features_array, 'VariableNames', feature_names);

% 3. 운동 예측 (어떤 모델이든 predict 함수 호출)
predictedExercise = classify(model, features_table);

end