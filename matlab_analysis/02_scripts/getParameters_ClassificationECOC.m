function codegen_args = getParameters_ClassificationECOC(model_struct, model_object, sensor_data_type)
% [OVERVIEW] mySVMModel.mat의 실제 파일 구조에 100% 기반하여 파라미터를 추출합니다.

    binary_learners = model_object.BinaryLearners;
    num_learners = numel(binary_learners);
    if num_learners > 0
        num_features = size(binary_learners{1}.Beta, 1);
    else
        error('SVM 모델에 바이너리 학습기가 없습니다.');
    end
    
    all_betas = zeros(num_features, num_learners);
    all_biases = zeros(1, num_learners);
    for i = 1:numel(binary_learners)
        all_betas(:, i) = binary_learners{i}.Beta;
        all_biases(i) = binary_learners{i}.Bias;
    end
    class_names = model_object.ClassNames;
    coding_matrix = model_object.CodingMatrix;
    
    % --- ▼▼▼ [핵심 수정] 더 이상 존재하지 않는 Mu와 Sigma를 찾지 않습니다. ▼▼▼
    mu = []; % 표준화되지 않았으므로 빈 배열로 지정
    sigma = []; % 표준화되지 않았으므로 빈 배열로 지정
    
    % '상자(model_struct)'에서 공식 이름표 목록을 가져옵니다.
    required_vars = model_struct.RequiredVariables;

    codegen_args = {sensor_data_type, coder.Constant(all_betas), coder.Constant(all_biases), ...
                    coder.Constant(class_names), coder.Constant(coding_matrix), ...
                    coder.Constant(mu), coder.Constant(sigma), coder.Constant(required_vars)};
end