% HW10_problem1.m

% Create a 3-d plot of the function 1/exp(42 x2 y2) with x and y 
% varying from -1 to 1. Use the functions meshgrid and mesh. Hint: \
% be careful about using the dot with the operator, e.g. "*" vs 
% ".*", because in this problem getting it wrong may not produce 
% an error message but it will produce an incorrect plot.

% Tate Finley, 11/15/22
% Rev. 11/15/22

% generate x and y values between -1 and 1
[x,y] = meshgrid(linspace(-1,1,1001));

% calculate given function
f = 1./exp(42*(x.^2).*(y.^2));

% produce 3D plot and label
mesh(x,y,f);
xlabel('x')
ylabel('y')
zlabel('f(x,y)')
title('1/exp(42*x^2*y^2)')