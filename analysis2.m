Tg = readtable('gyro_250828_1852.csv');
Ta = readtable('accel_250828_1852.csv');

% time 파싱
Tg.time = datetime(Tg.time,'InputFormat','yyyy-MM-dd HH:mm:ss.SSS');
Ta.time = datetime(Ta.time,'InputFormat','yyyy-MM-dd HH:mm:ss.SSS');

tg = seconds(Tg.time - Tg.time(1));
ta = seconds(Ta.time - Ta.time(1));

figure; plot(tg,Tg.X); hold on; plot(tg,Tg.Y); plot(tg,Tg.Z);
title('Gyro (rad/s 추정)'); legend('X','Y','Z'); xlabel('s');

figure; plot(ta,Ta.X); hold on; plot(ta,Ta.Y); plot(ta,Ta.Z);
title('Accel (m/s^2, 중력 포함)'); legend('X','Y','Z'); xlabel('s');
