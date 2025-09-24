clear all
x = [0.8, 1.0, 1.3, 1.65, 1.9, 2.2, 2.6, 2.95, 3.3, 3.5; 1.02, 2.04, 3.06, 4.08, 5, 6.02, 7.04, 8.06, 9.08, 10; 0.72, 0.83, 0.91, 1.03, 1.13, 1.26, 1.39, 1.55, 1.71, 1.80];
flow_rate = x(1,:);
Vin = x(2,:);
Vout = x(3,:);

figure, plot(Vin,flow_rate,'Color','b'), grid;
title('Flow Rate versus Voltage');
xlabel('Voltage (V)');
ylabel('Flow Rate (L/min)');
p = polyfit(Vin,flow_rate,1);
slope = p(1,1)
offset = p(1,2)