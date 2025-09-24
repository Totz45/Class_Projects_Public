% capacitor_impedance
% This script computes and plots the impedance for a capacitor
% Inputs are resistance(R), capacitance(C), and series inductance(L)

C = input('Enter Capacitance in Farads:  ');
L = input('Enter Inductance in Henrys:  ');
R = input('Enter Resistance in Ohms:  ');

f = logspace(5,9,1001);

mag = sqrt(R^2+(2*pi.*f.*L-1./(2*pi.*f.*C)).^2);

loglog(f,mag);
xlabel('Frequency(Hz)');
ylabel('Magnitude(Ohms)');
title('Impedance of a Realistic Capacitor');