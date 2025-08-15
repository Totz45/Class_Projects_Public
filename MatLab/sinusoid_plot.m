% plot a sinusoid with user-specified frequency and duration
f = input('Enter frequency (Hz): ');
duration = input('Enter duration (s): ');
t = linspace(0,duration,1001);
y = sin(2*pi*f*t);
plot(t,y)
xlabel('Time (s)')
ylabel('Amplitude (V)')
title('Sinusoid')