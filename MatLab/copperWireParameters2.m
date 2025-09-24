function [rpf, diameterin] = copperWireParameters2 (AWG, resistivity)
%  [rpf, diameterin] = copperWireParameters2(AWG)
%       returns the resistance per foot and diameter in inches
%       of a copper wire. Based on only wire gauge
%  [rpf, diameterin] = copperWireParameters2(AWG,resistivity)
%       returns the resistance per foot and diameter in inches
%       of a copper wire. Based on wire gauge and wire resistivity 

%  ^ help function

% All equations come from the ASTM standard B258-18.  
% This is also where the reference to the American Wire
% Gauge can be found for each individual parameter.

% This is where the function ends if the number passed is less than zero
assert(AWG > 0, 'Error: Your number must be greater than 0');

switch nargin
    case 2
        % To solve for the diameter, I first found an equation for step 
        step = 40 - (AWG + 3);

        % which can be plugged in to solve for diameter
        diameter = (5 .* (1.1229322.^(step-1)));

        % the previous diameter was in mils (1 mil = 0.001 in) provided by 
        % reference
        diameterin = diameter .* (10^-3);

        %equation found in ASTM sheet
        areamm = (diameter.^2) * 5.067 * (10^-4);

        %conversion from mm^2 to ft^2
        areaft = areamm .* 92903.04;
        
        %resistance per foot equals resistivity over area.
        rpf = resistivity/areaft;
    case 1
        % To solve for the diameter, I first found an equation for step 
        step = 40 - (AWG + 3);

        % which can be plugged in to solve for diameter
        diameter = (5 .* (1.1229322.^(step-1)));

        % the previous diameter was in mils (1 mil = 0.001 in) provided by 
        % reference
        diameterin = diameter .* (10^-3);
        % for rpf or resistance per foot, there was an equation to solve for
        % ohms/1000 ft so I solved that equation for ohms/1 ft shown below
        rpf = (905.44 ./(diameter.^2 .* 8.89)) .* 0.10535;
end

end

% copperWireParameters2.m

% Write a function which computes copper wire parameters 
% from the wire gauge. The function takes as input argument 
% the American wire gauge (AWG) which is an integer (for 
% simplicity restrict the wire gauge to be 0 or a larger number; 
% output an error message if the wire gauge is less than 0) and 
% produces as output arguments two values, the first is the wire 
% resistance per foot and the second is the wire diameter in 
% inches. You will need to find equations for these items - 
% include references to the source of equations in the function 
% comments (but not as part of the help). Include help with the 
% function. Show the results for the following: (a) 8 gauge, and 
% (b) 24 gauge wire. See class notes for additional information.
% Example: [a,b]=myfunction(16) produces result a=4e-3 
% b=5e-2 (note: values shown here are rounded).

% Tate Finley, 10-13-22,
% Rev. 10-13-22 