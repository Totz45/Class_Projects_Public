% HW9_Problem2.m
%
% A rectangular pulse of amplitude 5 V, starting (rising edge) 
% at t = 0 s and stopping (falling edge) at t = 0.008 s, is 
% input to a RC lowpass filter circuit (figure here) with 
% R = 1.5 kΩ and C = 2.2 µF. Write the circuit equation then 
% write a script which uses the solve function to determine the 
% output voltage and plots both the input and output voltages 
% as a function of time. Include a legend on the plot which 
% identifies the input and output voltages.
%
% Tate Finley, 10-20-22,
% Rev. 10-20-22

% equation of the circuit -- dvc/dt = Vs/RC - vc/RC

% implementation for solving for the output voltages
syms Vs R C vc(t);
ode = vc == Vs - (R*C)*diff(vc,t);
cond = vc(0)==0;% the pulse is not active before t=0 so vc = 0


% differentiate to get vc
vcSol = dsolve(ode,cond);
pulse = 5*rectangularPulse(0,0.008,t);
% Plotting input voltage using rectangular pulse
fplot(pulse, [-1,1],'DisplayName','Vin');
hold on

% Plotting output voltage from t=-0.01 to t=0.02
%fplot(subs(vcSol,[Vs R C], [5*rectangularPulse(0,0.008,t) 1500 0.0000022]),[-0.01,0.008],'DisplayName','Vout = t<0.008');
% This plot is equivalent to the natural response + forced response 
% the moment when Vs=0 and t<0
fplot(subs(vcSol,[Vs R C], [pulse 1500 0.0000022]),[-1,1],'DisplayName','Vout = t>0.008');
hold off

% adjusting plot
legend('show');
xlim([-0.01,0.02]);
ylim([-0.1,5.1]);
xlabel('Time(s)');
ylabel('Voltage (V)');
title('RC lowpass filter circuit');