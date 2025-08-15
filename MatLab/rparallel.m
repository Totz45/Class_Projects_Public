
function [req,peq] = rparallel(resistorP, powerP)
%  [req,peq] = rparallel(resistorP, powerP)
%       returns the equivalent resistance and the equivalent power rating
%       of a given network of resistors and power ratings.

%  ^ help function

% asserting that the vector arguments are equal
assert(length(resistorP) == length(powerP), 'Error, the length of the arguments are not equal');

% creating an anonymous function to calculate equivalent resistance in
% parallel then sending data to the output
parallelResistance = @ (r) (1/sum((1./r)));
req = parallelResistance(resistorP);

% calculation of equivalent power rating for parallel resistors
peq = min(powerP).*length(powerP);

end

% rparallel.m

% Write a function named rparallel which computes the equivalent 
% resistance and power rating for a network consisting of resistors 
% connected in parallel. The function arguments are two row or 
% column vectors (they should be of equal length, length≥1), the 
% first containing resistance values and the second containing 
% corresponding power ratings. The function returns two values, 
% equivalent resistance and power rating. Check for errors in the 
% function arguments (use assert statements). Use a anonymous 
% function to compute the equivalent resistance of resistors 
% in parallel in this function.

% Tate Finley, 10-6-22,
% Rev. 10-6-22 