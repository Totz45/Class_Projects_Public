% Thevenin_equivalent.m

% To characterize a device which is thought to behave like 
% a Thévenin equivalent source, an experiment is conducted 
% in which various load resistors are connected to the device 
% and the voltage and current at the device output are measured. 
% Perform a curve fit to the data in order to determine Vth and 
% Rth of the Thévenin equivalent source model, and plot the 
% actual data (as points) and the Thévenin equivalent source 
% model (as a line), with current on the horizontal axis. 
% Add a legend to the plot to identify which is the data and 
% which is the model. Annotate the plot (see the "annotation" 
% command) with the Thévenin equivalent source model parameters. 

% Tate Finley, 10-13-22,
% Rev. 10-13-22

% get Device loads
vload = input('Enter device voltage load:  ');
iload = input('Enter device current load:  ');

% produce a linear fit based on loads
curveFit = polyfit(iload,vload,1);

% evaluate curve fit
vFit = polyval(curveFit,iload);

% plot function and add legend, axis labels, title and annotation
plot(iload,vload,'o','DisplayName','Data');
hold on;
plot(iload,vFit,'-','DisplayName','Model');
hold off;
legend('show');
xlabel('Current (A)');
ylabel('Voltage (V)');
title('Device relation to Thevenin Equivalent model');
annotation('textbox','String','Slope = Rth, Yint. = Vth','FitBoxToText','on');
