%T=normal000Ch08100gPEAcceleration.VarName1;
%X=normal000Ch08100gPEAcceleration.VarName2;
%Y=normal000Ch08100gPEAcceleration.VarName3;
%Z=normal000Ch08100gPEAcceleration.VarName4;

A=fft(X);
%A=fft(Y);
%A=fft(Z);
Fs=20000;
Period=1/Fs;
L=99932;
P2=abs(A/L);
P1=P2(1:L/2+1);
P1(2:end-1)=2*P1(2:end-1);
f=Fs*(0:(L/2))/(L);
plot(f,P1);