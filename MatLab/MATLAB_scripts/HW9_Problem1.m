% HW9_Problem1.m
%
% Write a script which symbolically integrates the function 
% x^5 e^x and prints the result.
%
% Tate Finley, 10-20-22,
% Rev. 10-20-22

syms x; % make x a symbolic variable
f(x) = x^5*exp(x); % equation to integrate
int(f,x) % integration of symbolic function


