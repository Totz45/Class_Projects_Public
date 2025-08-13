/*
	File Name: tafinley43.cpp
	Author: Tate Finley
	Date: 2/18/23
	Purpose: Find the maximum element in a list of integers using 
             a brute force solution. 
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

/*
    Function Name: usage()
    Purpose: Outputs for basic command line arguments to use in the program
    Parameters: the name of the program
    Returns: None
*/
void usage(char* name) {
    std::cerr << "Calculates the maximum element given a text file with a list";
    std::cerr << " of numbers/integers.\nusage: " << name << " [file].txt\n";
    std::cerr << "file is the name of the text file.\n";
}

/*
    Function Name: maxElement()
    Function Purpose: Calculates the greatest element in a given list
    Parameters: A vector with the list of numbers
    Returns: None
*/
void maxElement(std::vector <int> numberList) {
    int maxVal = numberList[0];//maxVal holds maximum element

    //Compare maxVal to each element
    for(unsigned int i = 1; i < numberList.size(); i++)
    {
        if(maxVal < numberList[i])
        {
            maxVal = numberList[i];//assign if element is greater than maxVal
        }
    }
    std::cout << maxVal << std::endl;//output result.
}

/*
    Function Name: readFile()
    Function Purpose: reads from file to obtain numbers to insert into the vector/list.
    Parameters: the text file string, and a vector to be returned by reference
    Returns: None
*/
void readFile(std::string numberFile, std::vector <int> &storeNumber) {
    std::ifstream readNumbers;//input file
    int num;//stores current readable number
    readNumbers.open(numberFile);

    //find if the text file was able to be opened then output an error if not
    if(readNumbers.is_open())
    {
        //read and remove whitespace
        while(!(readNumbers>>std::ws).eof())
        {
            //if the file was able to be opened read numbers 
            readNumbers >> num;
            //make sure its only integers that it is reading
            if(readNumbers.fail())
            {
                std::cerr << "Unable to read file because a character was found.\n";
                break;
            }
            //must be integer put in container
            storeNumber.push_back(num);
        }

        //check eofbit to prevent failbit from entering
        if((readNumbers>>std::ws).eof())
        {
            maxElement(storeNumber);
        }

        readNumbers.close();
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
}


int main(int argc, char *argv[]) {
    
    std::string textFile = argv[1];//The text file to be opened
    std::vector <int> numberList;//vector to store the list of numbers

    //check for arguments
    if(argc != 2) {
		std::cerr << "Invalid number of arguments." << std::endl << std::endl;
        usage(argv[0]);
		return 0;
	}

    //read file
    readFile(textFile, numberList);
 
    return 0;
}