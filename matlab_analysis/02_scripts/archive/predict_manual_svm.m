function predicted_class_index = predict_manual_svm(sensorData, all_betas, all_biases, coding_matrix, required_vars, class_names)
%#codegen
% =========================================================================
% [ SCRIPT ]    : predict_manual_svm.m (설계도 기반 최종 버전)
% [ OVERVIEW ]
%   mySVMModel.mat의 공식 설명서 절차를 100% 따르는 수동 예측 함수입니다.
% =========================================================================

    % --- 1단계: 특징 추출 ---
    features_array = feature_extractor_codegen(sensorData);

    % --- 2단계: 테이블 생성을 통한 특징 순서 보장 ---
    features_table = array2table(features_array, 'VariableNames', required_vars);
    ordered_features = features_table{1,:};
    
    % --- 3단계: 개별 점수 계산 (단순하고 확실한 방식) ---
    num_learners = size(all_betas, 2);
    scores = zeros(1, num_learners);
    for i = 1:num_learners
        % Coder가 이해하기 가장 쉬운 단순 내적(dot product) + 덧셈 연산
        scores(i) = dot(ordered_features, all_betas(:,i)) + all_biases(i);
    end

    % --- 4단계: ECOC 디코딩을 통한 최종 판별 ---
    num_classes = size(class_names, 1);
    losses = zeros(1, num_classes);
    for i = 1:num_classes
        % sign(scores)는 각 점수를 +1, -1, 0으로 변환합니다.
        loss = sum(abs(coding_matrix(i, :) - sign(scores)));
        losses(i) = loss;
    end

    [~, predicted_class_index] = min(losses);
end