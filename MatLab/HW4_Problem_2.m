% HW4_Problem_2.m

% Write a script which generates a row vector containing a specified
% quantity of Gaussian random values (use 'randn') and outputs the
% number of those values which are positive. Use 'input' to prompt
% the user to input the quantity to generate and 'fprintf' to output
% the result. Run the script two times for each of the following
% quantities of random values: 1 , 4 , 100 (that's a total of six
% runs). Hint: because logical results can be used as numeric values,
% false=0 and true=1, using the 'sum' function on the results of
% an appropriate logical operator will make the computation easy.

% Tate Finley, 9-15-22,
% Rev. 9-16-22

n = input ('Enter the size of the vector: ');% input size of vector

% prints out the number of Gaussian random values of size, n in the vector
sum(randn(1, n)>0) 
% deleted unnessesary code