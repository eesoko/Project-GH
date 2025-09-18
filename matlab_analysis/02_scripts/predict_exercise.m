% --- predict_exercise.m 파일의 최종 내용 ---

function label = predict_exercise(input_features)
    % '깨끗한' 모델 파일인 cleanModel.mat을 로드합니다.
    s = coder.load('cleanModel.mat');

    % 이제 s는 바로 'actual_model' 객체를 포함하고 있습니다.
    label = predict(s.actual_model, input_features);
end