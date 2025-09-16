function predicted_class_index = predictExercise_ClassificationECOC(sensorData, all_betas, all_biases, class_names, coding_matrix, mu, sigma, required_vars)
%#codegen
% [OVERVIEW] "How To Predict"의 지시대로 테이블을 생성하여 예측을 수행합니다.

    % 1. 특징 추출 (순서가 보장되지 않은 1xN 숫자 배열)
    features_array = feature_extractor_codegen(sensorData);

    % --- ▼▼▼ [핵심] 안내문대로, 이름표를 붙여 '테이블'을 만듭니다. ▼▼▼
    % 이 과정을 통해 데이터의 '순서'가 required_vars의 순서와 100% 일치하게 됩니다.
    features_table = array2table(features_array, 'VariableNames', required_vars);
    
    % 테이블에서 데이터를 다시 배열로 추출합니다. 이제 이 배열은 순서가 완벽하게 정렬된 상태입니다.
    ordered_features = features_table{1,:};

    % 2. 표준화: 순서가 보장된 데이터로 단위를 변환합니다.
    if ~isempty(mu) && ~isempty(sigma)
        standardized_features = (ordered_features - mu) ./ sigma;
    else
        standardized_features = ordered_features;
    end
    
    % 3. 점수 계산: 이제 차원과 순서가 완벽하게 일치하므로 오류가 발생하지 않습니다.
    scores = standardized_features * all_betas + all_biases;

    % 4. ECOC 디코딩 (이하 동일)
    num_classes = size(class_names, 1);
    losses = zeros(1, num_classes);
    for i = 1:num_classes
        loss = sum(abs(coding_matrix(i, :) - sign(scores)));
        losses(i) = loss;
    end
    [~, predicted_class_index] = min(losses);
end