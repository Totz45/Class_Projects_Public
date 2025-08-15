clear all
load Lab6;
x = Lab6;
t = x(1,:);
Vt = x(2,:);
Vout = x(3,:);
figure, plot(t,Vt,'Color','b'), grid;
title('Vt versus time');
xlabel('Time (s)');
ylabel('Voltage (V)');
figure, plot(t,Vout,'Color','r'), grid;
title('Vout versus time');
xlabel('Time (s)');
ylabel('Voltage (V)');
