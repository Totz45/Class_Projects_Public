% HW10_problem2.m

% Plot the gain in decibels and phase in degrees of the transfer 
% function H(ω) = 103 j ω / ( 200 + j ω) where omega is frequency 
% in radians per second. Use subplot to create two plots, one below 
% the other, in the same figure window with one showing gain and 
% the other showing phase. The equation for gain in decibels is 
% 20log10(magnitude(H)). Select an appropriate frequency range for 
% the plot (hint: the gain will be a horizontal line in one part 
% and a sloping line in another part; if both parts are not shown 
% the frequency range is not appropriate.

% Tate Finley, 11/15/22
% Rev. 11/15/22

omega = logspace(0,5,1001); %assign values to omega

% transfer function equation
s = 1j*omega;
H = 10^3*s./(200+s);

% solving for gain in decibils
gain = 20*log10(abs(H));

% plotting the gain
subplot(2,1,1);
semilogx(omega,gain);
ylabel('Gain(dB)');
title('Transfer Function H(W)');

% calculate the phase in degrees
phase = angle(H)*180/pi;

% plotting the phase
subplot(2,1,2);
semilogx(omega,phase);
ylabel('Angle(degrees)');
xlabel('Frequency (rad/s)')