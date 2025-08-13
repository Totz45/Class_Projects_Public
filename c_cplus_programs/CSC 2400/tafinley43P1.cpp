/*
	File Name: tafinley43.cpp
	Author: Tate Finley
	Date: 2/1/23
	Purpose: Find the greatest common denominator given two integers. 
*/
	

#include <iostream>
#include <sstream>
#include <cmath>
/*
	Function Name: gcd()
	Function Purpose: Implements Euclids algorithm to return the greatest
					  common denominator.
	Parameters: Two integers
	Returns: An integer containing the answer to the greatest common denominator
			 between two integers
*/
int gcd(int m, int n) {
	int r;// remainder of m % n

	//implementation of Euclid's algorithm
	r = abs(m) % abs(n);
	m = n;
	n = r;
	/*	return integer 'm' if remainder is 0, if not call recursively 
		with the two new integers calculated */
	if(n == 0)
	{
		return m;
	} else
	{
		return gcd(m, n);
	}
}

/*
	Function Name: calculate_gcd()
	Function Purpose: Finds and outputs the greatest common denominator
	Parameters: two integers
	Returns: None
*/
void calculate_gcd(int m, int n) {
	
	//Outputs are based on given cases and expected outcomes
	if(m == 0 && n == 0)
	{
		std::cout << "gcd(" << m << "," << n << ") is undefined"<< std::endl;
	} else if(m == 0)
	{
		std::cout << "gcd(" << m << "," << n << ") = "<< n << std::endl;
	} else if(n == 0)
	{
		std::cout << "gcd(" << m << "," << n << ") = "<< m << std::endl;
	} else
	{
		std::cout << "gcd(" << m << "," << n << ") = "<< gcd(m, n) << std::endl;
	}
}



void usage(char *name) {
	std::cerr << "Calculates the greatest common divisor of two numbers." << std::endl;
	std::cerr << "usage:" << name << " [m] [n]" << std::endl;
	std::cerr << "m,n integers, not both zero" << std::endl;
}

int main(int argc, char *argv[]) {
	int m = 0;
	int n = 0;

	if(argc != 3) {
		std::cerr << "Invalid number of arguments." << std::endl << std::endl;
		usage(argv[0]);

		return 0;
	}

	std::istringstream iss(argv[1]);
	if((iss>>m).fail() || !iss.eof()) {
		std::cerr << argv[1] << " is not a valid integer." << std::endl << std::endl;
		usage(argv[0]);

		return 0;
	}

	iss.str(argv[2]);
	iss.clear();
	if((iss>>n).fail() || !iss.eof()) {
		std::cerr << argv[2] << " is not a valid integer." << std::endl << std::endl;
		usage(argv[0]);

		return 0;
	}

	calculate_gcd(m, n);

	return 0;
}
