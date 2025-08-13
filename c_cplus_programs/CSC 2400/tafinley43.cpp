/*
	File Name: tafinley43.cpp
	Author: Tate Finley
	Date: 4/23/2023
	Purpose: Compute the Levenshtein distance (minimum cost) of two strings using dynamic programming 
*/


#include <algorithm>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include <cstddef>

void print_table(const std::vector<std::vector<int> > &table, const std::string &first, const std::string &second) {
	std::vector<std::string> str_row;
	std::vector<std::vector<std::string> > str_table;

	str_row.push_back("");
	str_row.push_back("");
	for(char c :second) {
		str_row.push_back(std::string{c});
	}
	str_table.push_back(str_row);
	for(size_t ii=0; ii < table.size(); ii++) {
		str_row.clear();
		if(ii == 0) {
			str_row.push_back("");	
		}
		else {
			str_row.push_back(std::string{first[ii-1]});	
		}
		for(int val : table[ii]) {
			str_row.push_back(std::to_string(val));
		}
		str_table.push_back(str_row);
	}

	std::vector<int> widths(str_table[0].size());
	for(std::vector<std::string> &str_row : str_table) {
		for(size_t ii=0; ii < str_row.size(); ii++) {
			widths[ii] = std::max(widths[ii], (int)str_row[ii].size());
		}
	}

	for(size_t ii=0; ii < str_table.size(); ii++) {
		for(size_t jj=0; jj < str_table[ii].size(); jj++) {
			std::cout << std::right << std::setw(widths[jj]+1);
			std::cout << str_table[ii][jj];
		}
		std::cout << std::endl;
	}
}

/*
	Function Name: minimumCost()
	Function Purpose: find the minimum cost of inserting, deleting, or substituting a character.
*/
int minimumCost(std::vector<std::vector<int> > &table, int i, int j, int deletion_cost=1, int insertion_cost=1, int substitution_cost=1)
{
	int minCost = deletion_cost + table[i-1][j];//cost of deletion
	int insCost = insertion_cost + table[i][j-1];//cost of insertion
	int subCost = substitution_cost + table[i-1][j-1];//cost of substitution
	if(minCost > insCost)
	{
		minCost = insCost;
	}
	if(minCost > subCost)
	{
		minCost = subCost;
	}
	return minCost;
}

int levenshtein_distance(const std::string &first, const std::string &second, int deletion_cost=1, int insertion_cost=1, int substitution_cost=1) {
	std::vector<std::vector<int> > table(
		first.size()+1,
		std::vector<int>(second.size()+1, 0)
	);
	
	unsigned int m = first.size();//size of first string
	unsigned int n = second.size();//size of second string
	for(unsigned int i = 0; i <= m; i++)
	{
		for(unsigned int j = 0; j <= n; j++)
		{
			//based on recursive function
			if(i == 0 && j == 0)
			{
				table[i][j] = 0;
			} else if(j == 0)
			{
				table[i][j] = deletion_cost * i;
			} else if(i == 0)
			{
				table[i][j] = insertion_cost * j;
			} else if(first[i-1] == second[j-1])
			{
				table[i][j] = table[i-1][j-1];
			} 
			else
			{
				table[i][j] = minimumCost(table, i, j, deletion_cost, insertion_cost, substitution_cost);
			}
		}
	}
	
	//print_table(table, first, second);
	
	return table[first.size()][second.size()];
}

void usage(int argc, char *argv[]) {
	if(argc == 2) {
		std::cerr << "Two strings are needed to calculate Levenshtein distance." << std::endl << std::endl;
	}
	else if(argc > 3) {
		std::cerr << "Error, too many command line arguments." << std::endl;
		std::cerr << "Two strings are needed to calculate Levenshtein distance." << std::endl << std::endl;
	}   
	std::cout << "Levenshtein Distance - finds the Levenshtein distance between two strings." << std::endl;
	std::cout << "usage: ";
	std::cout << argv[0] << " [first] [second]" << std::endl;
	std::cout << "  first - the first string that is to be converted into the second" << std::endl;
	std::cout << "  second - the second string that that first string is coverted into" << std::endl << std::endl;
}


int main(int argc, char *argv[]) {
	if(argc != 3) {
		usage(argc, argv);
	}   
	else {
		std::cout << levenshtein_distance(argv[1], argv[2]) << std::endl;
	}   
	return 0;
}

