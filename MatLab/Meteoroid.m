% Meteoroid.m

% This script computes and plots the function N(>D) = 37*D^-2.7 where D is the
% diameter and an input for the script, N(>D) is the expected number of objects.

% Tate Finley, 10/21/22
% Rev. 10/21/22

Dmin = input('Enter minimum x-axis value:  ');
Y = input('Enter scaling for Y 1)Linear 2)logarithmic: ');
Dmax = 300;
D = logspace(log10(0.05),log10(300),1001);
N = 37.*D.^-2.7;
if Y == 1
    semilogx(D,N);
elseif Y == 2
    loglog(D,N);
end    
xlim([Dmin,Dmax]);
xlabel('Diameter (m)');
ylabel('Number');
title('Meteor Impacts on Earth: Expected number per year of objects larger than a given diameter')
