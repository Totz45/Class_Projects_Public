% HW3_Problem_1.m

% Write a script to compute the equivalent resistance of two resistors
% connected in parallel. Use "input" to prompt the user
% to enter resistance values and use "fprintf" to show the result.
% Test the script using values 1200 Ω and 820 Ω.

% Tate Finley, 9-8-22,
% Rev. 9-8-22

R1 = input('Enter the value for Resistor 1: '); % input for resistor 1
R2 = input('Enter the value for Resistor 2: '); % input for resistor 2

% equation for parallel resistance
IRp = (1/R1) + (1/R2); % IRp represents 1/Rp, 
Rp = (1/IRp);

% output and result of parallel resistance 
fprintf('\nThe value for those two resistors in parallel is: %.4g Ohms\n', Rp);
