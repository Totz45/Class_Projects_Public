clear all
x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10; 217.4, 437.9, 674.3, 905.8, 1141, 1375, 1603, 1837, 2073, 2299];

Vin = x(1,:);
tachometer = x(2,:);

figure, plot(tachometer,Vin,'Color','b'), grid;
title('Voltage versus Motor Speed');
ylabel('Voltage (V)');
xlabel('Motor Speed (RPM)');
p = polyfit(tachometer,Vin,1);
slope = p(1,1)
offset = p(1,2)