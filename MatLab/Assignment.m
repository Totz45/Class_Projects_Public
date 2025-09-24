Vo = 6; % Vo is the voltage output of the opamp circuit
Vs = 10e-3; % Vs is the voltage input of the opamp circuit
A = Vo / Vs; % gain is Vo divided by Vs
R1 = 100; % resistor 1 is 100 ohms
R2 = R1 * (A - 1); % solve for resistor 2