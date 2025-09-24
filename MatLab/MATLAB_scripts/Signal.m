% This Matlab script calculates and plots the signal amplitude from 
% -2 < t < 1 for a given value of K
K = input('Enter value for K (in volts):  ');
t = linspace(-2,1,1001);
v = K.*exp(t./2).*cos(42*pi.*t);
plot(t,v);
xlabel('Time(s)');
ylabel('Amplitude (V)');
title('K-Signal Number 2');