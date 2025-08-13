/*
    File Name: tafinley43_prog3.cpp
    Author: Tate Finley
    Date: April 4th, 2022
    Purpose: This program reads from the three text documents in the zip file and prints out
             the information found in dinoDirectory.txt into three separate output files
             according to whether each 'dino' is considered to be a carnivore, a herbivore,
             or not a dino. It uses files, functions, and arrays to execute this program.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

int carnOrHerb(string);
bool searchCarnivore(string);
bool searchHerbivore(string);
void printDino(ofstream&, ifstream&, string, int[]);
bool overTenGrand(string);
void printResult(int[], string[]);

int main()
{
    ifstream inFile; //main input file
    string dinoDirFile; //gets filename from user
    string tempString; //holds current information up until '#'
    ofstream outFile; //main output file
    int totalsArray[6] {0, 0, 0, 0, 0, 0}; //6 element array intialized to 0.
    string labelsArray[6] {"TOTAL DINOS", "TOTAL CARNIVORE DINOS", "TOTAL HERBIVORE DINOS", 
                            "DINOS OVER 10,000 LBS", "DINOS NAMES END IN 'SAURUS'", "ANIMALS NOT DINOS"};
                            //6 element string array intialized for printResult function
    string dinoName; //holds dinosaur name
    

    //user inputs text document to open, has to be dinoDirectory.txt
    cout << "Dinosaur Directory File Name (dinoDirectory.txt): ";
    getline(cin, dinoDirFile);
    inFile.open(dinoDirFile);

    //validates that the user inputed the correct file
    while(dinoDirFile != "dinoDirectory.txt")
    {
        cout << "That is not the file name, type dinoDirectory.txt: ";
        getline(cin, dinoDirFile);
        inFile.open(dinoDirFile);
    }

    //checks if file is opened
    if(inFile.is_open()) 
    {
        //loops until the information in dinoDirectory.txt ends
        while(!inFile.eof()) 
        {
            //checks if no stream errors
            if(inFile.good()) 
            {
                //while loop using tempString to hold information until '#'
                while(getline(inFile, tempString, '#'))
                {
                    dinoName = tempString; //first '#' contains information about name of dinosaur
                    
                    //adds to 5th element if the name contains "saurus" 
                    if(tempString.find("saurus") != string::npos)
                    {
                        totalsArray[4] += 1;
                    }

                    /* These if, if-else, and else statements call the function carnOrHerb() which
                       will return (1) if dino is carnivore, (2) if dino is herbivore, or (-1) dino
                       is in fact not a dinosaur. Then they will add to the corresponding totalsArray
                       element according to the statements stored in labelsArray. Next, a statement will
                       indicate which file the information is being printed to for each dino. Finally it 
                       will open the corresponding output file and allow information to be added.*/
                    if(carnOrHerb(dinoName) == 1) 
                    {
                        totalsArray[0] += 1;
                        totalsArray[1] += 1;
                        cout << "\n" << dinoName << " is being printed to the CARNIVORE file!";
                        outFile.open("carnOutFile.txt", ios::app);
                    }else if(carnOrHerb(dinoName) == 2)
                    {
                        totalsArray[0] += 1;
                        totalsArray[2] += 1;
                        cout << "\n" << dinoName << " is being printed to the HERBIVORE file!";
                        outFile.open("herbOutFile.txt", ios::app);
                    }else 
                    {
                        totalsArray[5] += 1;
                        cout << "\n" << dinoName << " is being printed to the OTHER file!";
                        outFile.open("otherOutFile.txt", ios::app);
                    }
                    printDino(outFile, inFile, dinoName, totalsArray); //go to the function for more info
                }
                inFile.close();//closes dinoDirectory.txt

                printResult(totalsArray, labelsArray);//go to the function for more info
            } 
        }
    }
    
    

    return 0;
}

/* Function Name: carnOrHerb()
   Parameters: a string, holding the animal’s name
   Returns: an integer, indicating if the animal is a carnivore (1), herbivore (2), or other (-1)
   Purpose: calls the searchCarnivore function to check if the dinosaur is a carnivore (returns 1
   if true). If not, calls the searchHerbivore function to check if the dinosaur is a herbivore
   (returns 2 if true). If not, the dinosaur is not a dinosaur and returns -1.
*/
int carnOrHerb(string animalName)
{
    if(searchCarnivore(animalName) == true)
    {
        return 1;
    }else if(searchHerbivore(animalName) == true)
    {
        return 2;
    }else
    {
        return -1;
    }

}

/* Function Name: searchCarnivore()
   Parameters: a string, holding the animal’s name
   Returns: a Boolean, indicating true if the animal is a carnivore and false if it is not
   Purpose: Opens carnivores.txt, checks to make sure the file can be opened, searches for the 
   dinosaur name in the file, and then closes the file. If the dinosaur name is found, the 
   boolean returns true because it is a carnivore. If the dinosaur name can not be found, the 
   boolean returns false.
*/
bool searchCarnivore(string animalName)
{
    ifstream inCarnivoreFile;//carnivore input file
    string carnivoreIndicator;//holds information about dino names in carnivores.txt
    bool isCarnivore = false;//is the dinosaur a carnivore?

    inCarnivoreFile.open("carnivores.txt");

    if(inCarnivoreFile.is_open())
    {
        while(!inCarnivoreFile.eof())
        {
            if(inCarnivoreFile.good())
            {
                while(getline(inCarnivoreFile, carnivoreIndicator, '#'))
                {
                    if(animalName == carnivoreIndicator)
                    {
                        isCarnivore = true;
                    }
                }
            }
        }
    }

    inCarnivoreFile.close();

    return isCarnivore;


}

/* Function Name: searchHerbivore()
   Parameters: a string, holding the animal’s name
   Returns: a Boolean, indicating true if the animal is a herbivore and false if it is not
   Purpose: Opens herbivores.txt, checks to make sure the file can be opened, searches for the 
   dinosaur name in the file, and then closes the file. If the dinosaur name is found, the 
   boolean returns true because it is a herbivore. If the dinosaur name can not be found, the 
   boolean returns false.
*/
bool searchHerbivore(string animalName)
{
    ifstream inHerbivoreFile;//herbivore input file
    string herbivoreIndicator;//holds information about dino names in herbivores.txt
    bool isHerbivore = false;//is the dinosaur a herbivore?

    inHerbivoreFile.open("herbivores.txt");

    if(inHerbivoreFile.is_open())
    {
        while(!inHerbivoreFile.eof())
        {
            if(inHerbivoreFile.good())
            {
                while(getline(inHerbivoreFile, herbivoreIndicator, '#'))
                {
                    if(animalName == herbivoreIndicator)
                    {
                        isHerbivore = true;
                    }
                }
            }
        }
    }

    inHerbivoreFile.close();

    return isHerbivore;


}

/* Function Name: printDino()
   Parameters: an output file stream of the output file you are printing to, an input file 
   stream passed by reference of the input file (dinoDirectory.txt), a string containing the 
   name of the animal, and the integer array
   Returns: none
   Purpose: prints the name, height/length, mass, diet, and description found in the text 
   document, dinoDirectory to the corresponding output file. Also calls overTenGrand function
   to check if the dinosaur weighs more than 10,000 pounds.
*/
void printDino(ofstream& outputFile, ifstream& inputFile, string dinoName, int totalsArray[6])
{
    string tempString;//holds current information
    
    outputFile << "DINOSAUR NAME:\t" << dinoName << endl;
    getline(inputFile, tempString, '#');
    outputFile << "HEIGHT/LENGTH:\t" << tempString << endl;
    getline(inputFile, tempString, '#');
    if(overTenGrand(tempString) == true)
    {
       totalsArray[3] += 1; 
    }
    outputFile << "MASS:\t\t\t" << tempString << endl;
    getline(inputFile, tempString, '#');
    outputFile << "EATS:\t\t\t" << tempString << endl;
    getline(inputFile, tempString, '#');
    outputFile << "DESCRIPTION;\t" << tempString << endl << endl;
    outputFile.close(); 
}

/* Function Name: overTenGrand()
   Parameters: a string, holding the mass of the animal
   Returns: a Boolean, true if the animal is over 10,000 lbs and false otherwise
   Purpose: This function use an algorithm to find if the dinosaur is over 10,000 lbs.
*/
bool overTenGrand(string dinoMass)
{
    int i, j;//variables for algorithm
    bool isTenGrand = false;//is the dinosaur over 10,000 lbs?
    
    /*I observed that all dinos over 10,000 lbs had the word
      "to" in the mass description. This if statement checks
      to see if the mass decription of a dino contains the word
      "to".*/
    if(dinoMass.find("to ") != string::npos)
    {
        i = dinoMass.find("to");
        i = dinoMass.find(' ', i);//finds the space after "to" and assigns to i.
        j = dinoMass.find("0 ", i);//finds the space after "to" and the number after it to j.
        
        /*There should be 6 indexes between j and i accounting for the 4 numbers before the last number, 
          the comma, and the final number with the space counting as one index.*/
        if(j - i == 6)
        {
            isTenGrand = true;
        }

    }
    return isTenGrand;
}

/* Function Name: printResult()
   Parameters: two arrays – an integer array holding the totals and a string array holding the descriptions
   Returns: none
   Purpose: prints the labels and the totals in a nice, easy to read format.
*/
void printResult(int totalArray[6], string labelArray[6])
{
    string line(50, '-');//accounts for the horizontal row of dashes
    int i;//initializer in for loop

    cout << "\n\n" << line << endl;
    cout << setfill(' ');

    //prints out each labelArray element with the corresponding totalArray element.
    for(i = 0; i < 6; ++i)
    {
        cout << setw(30) << labelArray[i] << ": " << totalArray[i] << endl;
    }

    cout << line;
}