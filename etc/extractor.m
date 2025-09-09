% Extractor.m - '근황' 앱 센서 데이터 시각화 스크립트

clear; close all; clc;

% --- 1. 사용자에게 CSV 파일 선택창 띄우기 ---
[fileName, pathName] = uigetfile('*.csv', 'Select the sensor data CSV file');

% 만약 사용자가 파일을 선택하지 않고 창을 닫으면 스크립트 종료
if isequal(fileName, 0)
    disp('User selected Cancel');
    return;
else
    fullPath = fullfile(pathName, fileName);
    disp(['User selected: ', fullPath]);
end

% --- 2. CSV 파일 읽기 ---
% readtable 함수를 사용하여 CSV를 테이블 형식으로 불러옵니다.
% 파일에 헤더가 있으므로 자동으로 변수 이름을 인식합니다.
dataTable = readtable(fullPath);

% --- 3. 데이터 추출 ---
timestamp = dataTable.timestamp;
accelX = dataTable.ax;
accelY = dataTable.ay;
accelZ = dataTable.az;
gyroX = dataTable.gx;
gyroY = dataTable.gy;
gyroZ = dataTable.gz;

% --- 4. 그래프 그리기 ---
figure('Name', fileName, 'NumberTitle', 'off'); % Figure 창 제목을 파일 이름으로 설정

% 첫 번째 서브플롯: 가속도계
subplot(2, 1, 1);
plot(accelX, 'b-', 'LineWidth', 1.5);
hold on;
plot(accelY, 'r-', 'LineWidth', 1.5);
plot(accelZ, 'g-');
hold off;
title('Accelerometer Data');
xlabel('Samples');
ylabel('Acceleration (m/s^2)');
legend('X-axis', 'Y-axis', 'Z-axis');
grid on;

% 두 번째 서브플롯: 자이로스코프
subplot(2, 1, 2);
plot(gyroX, 'b-', 'LineWidth', 1.5);
hold on;
plot(gyroY, 'r-', 'LineWidth', 1.5);
plot(gyroZ, 'g-');
hold off;
title('Gyroscope Data');
xlabel('Samples');
ylabel('Angular Velocity (rad/s)');
legend('X-axis', 'Y-axis', 'Z-axis');
grid on;