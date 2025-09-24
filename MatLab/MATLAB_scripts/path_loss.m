function [pathLoss] = path_loss (distance,wavelength)
%   [pathLoss] = path_loss (distance,wavelength)     
%       This function computes the free-space path loss between a
%       transmitter and receiver. 
%       Needs distance and wavelength in meters in order

assert(all(distance > 0),'one of the distances is not greater than 0');
assert(all(wavelength > 0),'one of the wavelengths is not greater than 0');

pathLoss = 10*log10(4*pi.*distance./wavelength);

end
