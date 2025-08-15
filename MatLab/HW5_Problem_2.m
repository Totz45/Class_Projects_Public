% HW5_Problem_2.m

% Write a script which prints out a temperature conversion 
% table, using an appropriate loop statement. The output 
% should be in two columns with degrees Celsius in the left 
% column and degrees Fahrenheit in the right column. The 
% rows of the table should start at −20 degrees Celsuis, 
% stop at +50 degrees Celsius, and go in steps of 5 degrees 
% Celsius. At the top of the table include a title and column 
% labels.

% Tate Finley, 9-22-22,
% Rev. 9-22-22

% Printing title and column names
fprintf('\n          Temperature         \n');
fprintf('______________________________\n');
fprintf('|   Celsius   |  Fahrenheit  |\n');
fprintf('______________________________\n');

% loops from -20 to 50 in increments of 5
for c = -20:5:50
    f = 9/5*c + 32; % conversion from celsius to fahrenheit
    T = [c, f]; % T for temperature, c for celsius, f for fahrenheit
    fprintf('|     %3g     |     %3g      |\n', T); % prints temperature for given value
end
% end table
fprintf('|_____________|______________|\n');
