% HW4_Problem_1.m

% Write a script which prompts the user to input a radius, r, 
% in units of meters then outputs the following: (a) for a circle
% (2-dimensional) the area and circumference, and (b) for a sphere
% (3-dimensional) the volume and surface area.  Use 'input' and
% 'fprintf' statements.Use the assert statement to check that the
% radius entered is non-negative; output a user-friendly error
% statement if the assertion is false  ("user friendly" means
% a clear statement of the problem e.g. "radius must be 
% non-negative"). Test the script using the following input
% values (in meters): 7 , 0 , -3. 

% Tate Finley, 9-15-22,
% Rev. 9-16-22

r = input('Enter a radius (in meters):  '); % gets radius from user
%don't need if
% begin assertion, if it succeeds the script continues, 
% if not, statement prints
assert(r > 0, 'Error: Your number must be non-negative');
a = pi*(r^2); % formula for area of circle
c = 2*pi*r; % formula for circumference of circle
s = 4*pi*r^2; % formula for surface area of a sphere
v = (4/3)*pi*r^3; % formula for volume of a sphere
%prints each outcome
fprintf('\nFor a circle of radius %i\n', r);
fprintf('Area: %g Circumference: %g\n ', a, c);
fprintf('\n\nFor a sphere of radius %i\n', r);
fprintf('Volume: %g Surface Area: %g\n ', v, s);
