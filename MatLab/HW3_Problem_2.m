% HW3_Problem_2.m

% Write a script to plot the function "x times sine-squared of x"
% over a user-specified interval. The script should prompt the user
% to enter the starting and stopping values of x, perform the computation,
% and plot the result. Label the x-axis as Distance in meters,
% the y-axis as Altitude in meters, and title the plot as HW3 Problem 2.
% Test the script using start/stop values 28 and 42.

% Tate Finley, 9-8-22,
% Rev. 9-8-22

% user input for start and stop values
s = input('Enter the start value for x: '); % s is start value
t = input('Enter the stop value for x: '); % t is stop value

% compute and plot function
x = linspace(s,t,1001); % plot with user's start and end points
y = x.*(sin(x).^2); % function is x times sine-squared of x
plot(x,y); % Creates graph

% label the plot
xlabel('Distance (m)'); % Labels x-axis
ylabel('Altitude (m)'); % Labels y-axis
title('HW3 Problem 2'); % Labels title for plot
