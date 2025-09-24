clear all
x = [10, 20, 30, 40, 50, 60, 70, 80, 90; 1.2986, 1.3880, 1.4785, 1.5698, 1.6603, 1.7572, 1.8490, 1.9473, 2.0077];
ticks = x(1,:);
V = x(2,:);

figure, plot(V,ticks,'Color','b'), grid;
title('Voltage versus water level');
ylabel('Water level (tick mark)');
xlabel('Voltage (V)');
p = polyfit(V,ticks,1);
slope = p(1,1)
offset = p(1,2)