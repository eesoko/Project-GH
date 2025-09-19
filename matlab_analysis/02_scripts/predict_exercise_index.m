% =========================================================================
% [ SCRIPT ]    : predict_exercise_index.m
% [ VERSION ]   : 1.0
% [ PURPOSE ]   : Feature vector(1x32)를 입력받아 운동 라벨을 문자열로 반환
% =========================================================================
function idx = predict_exercise_index(features)
%#codegen
    s = coder.load('cleanModel.mat');
    [~, score] = predict(s.actual_model, features);   % 점수 행렬
    [~, k] = max(score, [], 2);                       % 가장 큰 확률 클래스
    idx = int32(k);                                   % 클래스 번호 (1, 2, 3, …)
end
