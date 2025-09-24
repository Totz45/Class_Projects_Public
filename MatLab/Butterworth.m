fc = 540;
f2c = 1545;
fs = 20000;

[b,a] = butter(6,[fc f2c]/(fs/2));

%freqz(b,a,[],fs)

%subplot(2,1,1)
%ylim([-100 20])

dataOutX = filter(b,a,X);
dataOutY = filter(b,a,Y);
dataOutZ = filter(b,a,Z);

plot(T,dataOutY)
%plot(T,dataOutY)
%plot(T,dataOutZ)
