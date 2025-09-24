% HW5_Problem_1.m

% The solution of the quadratic equation, a·x2 + b·x + c = 0
% (with real-valued coefficients), can be split into three
% cases (two real-valued roots, a pair of repeated roots, two
% case applies, and prints the solution. Use one or more 
% selection statements to handle the cases. The output, in 
% particular the complex numbers, should be displayed in a 
% "normal" form, i.e. what would be seen in a textbook. Test 
% your script using the following values (listed as triplets 
% (a,b,c)): (2,1,-1), (2,-8,26), (-4,-12,-9).

% Tate Finley, 9-22-22,
% Rev. 9-22-22

% The user inputs the values for each coefficent
a = input ('\nFor the equation, a·x2 + b·x + c = 0, \ninput the values for the coefficent of a: ');
b = input ('\n for coefficient b: ');
c = input ('\n for coefficient c: ');

% Using quadratic formula to calculate for both possible x values
xpos = (-b + sqrt(b^2 - 4*a*c))/(2*a);
xneg = (-b - sqrt(b^2 - 4*a*c))/(2*a);

% if both numbers are real and not the same, the if statement is entered
if isreal(xpos) && isreal(xneg) && xneg ~= xpos
    % indicate to user that both values are real
    fprintf('\nYour answer has two real value roots %f %f\n',xpos, xneg)
% if both numbers are the same, the elseif statement is entered
elseif xneg == xpos
    % indicate to user that both values are the same
    fprintf('\nYour answer has two real value repeated roots %f %f\n',xpos, xneg)
% that means both numbers are complex so the else statement executes
else 
    % indicate to user that both values are complex
    fprintf('\nYour answer has two complex value roots %fi %fi\n',xpos, xneg)
end