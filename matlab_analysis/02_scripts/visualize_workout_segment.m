% visualize_workout_segment.m - '리듬 점수' 기반 운동 구간 탐지 시각화 스크립트 (알고리즘 3.0)

clear; close all; clc;

% --- 1. 파일 선택 ---
[fileName, pathName] = uigetfile('*.csv', 'Select the sensor data CSV file');
if isequal(fileName, 0), disp('User selected Cancel'); return; else
    fullPath = fullfile(pathName, fileName); disp(['User selected: ', fullPath]);
end

% --- 2. 데이터 읽기 및 종합 신호 생성 ---
dataTable = readtable(fullPath);
allSensors = [dataTable.ax, dataTable.ay, dataTable.az, dataTable.gx, dataTable.gy, dataTable.gz];
signalMagnitude = sqrt(sum(allSensors.^2, 2)); % 6개 센서를 하나의 에너지 신호로 통합

% --- 3. 알고리즘 3.0: '리듬 탐지' ---
% --- 3a. 파라미터 설정 ---
Fs = 50; % 샘플링 주파수 (Hz)
windowSize = 2 * Fs; % 2초 크기의 '미니 클립' (윈도우)
overlap = 0.5; % 50%씩 겹치면서 이동
stepSize = floor(windowSize * (1 - overlap));
rhythmThreshold = 0.4; % 리듬 점수가 이 값보다 높으면 '운동 중'으로 간주

% --- 3b. '리듬 점수' 계산 (Autocorrelation 기반) ---
numWindows = floor((length(signalMagnitude) - windowSize) / stepSize) + 1;
rhythmScores = zeros(numWindows, 1);
windowCenters = zeros(numWindows, 1);

for i = 1:numWindows
    startIdx = (i-1)*stepSize + 1;
    endIdx = startIdx + windowSize - 1;
    
    windowData = signalMagnitude(startIdx:endIdx);
    windowData = windowData - mean(windowData); % DC 성분 제거
    
    % Autocorrelation 계산
    [autocorr, lags] = xcorr(windowData, 'coeff');
    
    % 주기성을 나타내는 첫 번째 피크 찾기 (0 lag 제외)
    [pks, ~] = findpeaks(autocorr(lags > 0));
    
    if ~isempty(pks)
        rhythmScores(i) = max(pks); % 가장 강한 주기성의 강도를 '리듬 점수'로
    else
        rhythmScores(i) = 0;
    end
    
    windowCenters(i) = startIdx + windowSize/2;
end

% --- 3c. '핵심 운동 블록' 탐지 ---
isRhythmic = rhythmScores > rhythmThreshold;
% 연속된 운동 블록 중 가장 긴 블록을 찾음
stats = regionprops(isRhythmic, 'Area', 'PixelIdxList');
if ~isempty(stats)
    [~, maxIdx] = max([stats.Area]);
    coreBlockIndices = stats(maxIdx).PixelIdxList;
    
    startWindow = coreBlockIndices(1);
    endWindow = coreBlockIndices(end);
    
    finalStartIdx = (startWindow - 1) * stepSize + 1;
    finalEndIdx = (endWindow - 1) * stepSize + windowSize;
else
    finalStartIdx = [];
    finalEndIdx = [];
end

% --- 4. 그래프 그리기 ---
figure('Name', ['Rhythm Detection Analysis: ', fileName], 'NumberTitle', 'off', 'WindowState', 'maximized');

% 서브플롯 1: 원본 에너지 신호와 탐지된 구간
subplot(2, 1, 1);
plot(signalMagnitude, 'Color', [0.7 0.7 0.7], 'DisplayName', 'Raw Energy');
hold on;
if ~isempty(finalStartIdx)
    xregion(finalStartIdx, finalEndIdx, 'FaceColor', 'g', 'FaceAlpha', 0.2, 'DisplayName', 'Detected Workout Segment');
end
title('Original Signal and Detected Segment');
xlabel('Samples'); ylabel('Signal Magnitude');
legend('show'); grid on;

% 서브플롯 2: '리듬 점수' 곡선과 최종 판단 과정
subplot(2, 1, 2);
plot(windowCenters, rhythmScores, 'b-o', 'LineWidth', 2, 'MarkerFaceColor', 'b', 'DisplayName', 'Rhythm Score');
hold on;
yline(rhythmThreshold, 'r--', 'LineWidth', 2, 'DisplayName', 'Rhythm Threshold (40%)');
if ~isempty(finalStartIdx)
    xregion(finalStartIdx, finalEndIdx, 'FaceColor', 'g', 'FaceAlpha', 0.2, 'DisplayName', 'Selected Core Block');
end
hold off;
title('Rhythm Score Curve & Core Block Selection');
xlabel('Samples (Center of Window)'); ylabel('Rhythm Score (Autocorrelation Peak)');
legend('show'); grid on;

% --- 5. 결과 출력 ---
if ~isempty(finalStartIdx)
    disp('------------------------------------');
    disp('Rhythm-based segment detection successful!');
    fprintf('Detected Start Index: %d\n', finalStartIdx);
    fprintf('Detected End Index:   %d\n', finalEndIdx);
    disp('------------------------------------');
else
    disp('Could not detect a rhythmic segment with the current settings.');
end