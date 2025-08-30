T = readtable('acce_250828_1823.csv');   % CSV 읽기
plot(T.X); hold on
plot(T.Y);
plot(T.Z);
legend('X','Y','Z');