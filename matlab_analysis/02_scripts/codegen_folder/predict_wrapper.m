function predicted_label = predict_wrapper(features_table, codegen_model_path)
%#codegen

% =========================================================================
% [ SCRIPT ]    : predict_wrapper.m (범용 예측 함수)
% [ OVERVIEW ]
%   1. coder.load: C++ 변환용으로 사전 처리된 모델(.mat)을 불러옵니다.
%   2. predict: 불러온 모델의 표준 predict 함수를 호출하여 예측을 수행합니다.
% =========================================================================

% persistent 키워드는 C++ 코드에서 모델 객체를 한 번만 로드하고
% 계속 재사용하도록 하여 성능을 향상시킵니다.
persistent model;
if isempty(model)
    % coder.load는 C++ 코드 생성 시에만 동작하는 특수 함수입니다.
    model = coder.load(codegen_model_path);
end

% 입력으로 받은 테이블(features_table)을 사용하여 예측을 수행합니다.
predicted_label = predict(model, features_table);

end