clear all
T = readtable('lab10.xlsx');
x = T.Time_s_;
y = T.Voltage_v_;
plot(x,y);
xlabel('Time (s)');
ylabel('Voltage (v)');
title('Motor Control System Response 10V');
K = sum(y(9:101,1))/93;
