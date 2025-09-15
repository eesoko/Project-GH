function predictedExercise = predictExercise(sensorData)
    %#codegen
    
    persistent modelObj;
    if isempty(modelObj)
        % ▼▼▼ [수정] 새로운 Coder 전용 모델 로더와 파일 이름을 사용합니다. ▼▼▼
        modelObj = loadLearnerForCoder('C:\Users\SeokHoLee\Desktop\Git\Project_GH\matlab_analysis\03_models\myKNNModel_coder.mat');
    end
    
    features = feature_extractor_codegen(sensorData);
    
    % loadLearnerForCoder로 불러온 모델은 바로 predict 함수를 사용할 수 있습니다.
    predictedExercise = predict(modelObj, features);
end