/*
    File Name: tafinley43_functions.cpp
    Author: Tate Finley
    Date: April 24th, 2022
    Purpose: Contains all function definitions for main function.
*/
#include "tafinley43_prog4.h"
/*
    Function Name: enterHeroes()
    Parameters: an integer indicating the current number of heroes in the 
                Heroes array, the maximum amount of heroes that can be 
                stored in the Heroes array and the Heroes array.
    Returns: an integer indicating the current number of heroes in the 
                Heroes array 
    Purpose: allows user to either enter information about a hero from a
             file or enter it manually.
*/
int enterHeroes(int maxHeroes, int currHeroes, Heroes heroArray[])
{
    int choice; //stores selection data
    bool goAgain = true;//allows another superhero to be entered manually
    int newHeroes = 0;//amount of heroes created using this function
    string fileName;//file name containing heroes
    string tempString;//temporary variable
    char tempChar;//temporary variable
    int tempInt;//temporary variable
    ifstream inputFile;//allows files to be read.
    //skips functions if the heroes array is full
    if(currHeroes >= maxHeroes)
    {
        cout << "Sorry! Your complex can only hold " << maxHeroes;
        cout << " heroes.\nYou can not add more." << endl;
    } else
    {
        //selection menu for inputing a superhero
        do {
            cout << "What do you want to do?\n";
            cout << "\t1.  Load the heroes from a file.\n";
            cout << "\t2.  Enter a hero manually.\n";
            cout << "\tChoose 1 or 2.\nCHOICE: ";
            cin >> choice;
            //validates choice
            if(choice < 1 || choice > 2)
            {
                cout << "\nInvalid response.\n";
            } else 
            {
               switch (choice) 
               {
                    case 1:
                        //if option 1 is selected this line of code executes
                        cout << "\nWhat is the name of the file with your list of superheroes? (ex: filename.txt)\n";
                        cout << "FILENAME: ";
                        cin.ignore();
                        getline(cin, fileName);
                        inputFile.open(fileName); //allows inputed file to open

                        //checks to see if the file can be opened
                        if(inputFile.is_open())
                        {
                            for(int i = currHeroes; i < maxHeroes; ++i)     
                            {
                                if(!inputFile.eof())
                                {
                                    int j = i;//serves as the index for the array
                                    while(getline(inputFile, tempString, '#')) 
                                    {
                                        
                                        if(currHeroes == maxHeroes)
                                        {
                                            break;/*whenever the current number of heroes exceeds the max allowed
                                                    the rest of the heroes after won't be in the array. This allows
                                                    the while loop to reach the end of the file without adding any
                                                    additional heroes to the heroes array*/
                                        }
                                        
                                        heroArray[j].heroName = tempString;//first getline is the hero name
                                        
                                        getline(inputFile, tempString, '#');
                                        heroArray[j].heroDescription = tempString;//next is the description
                                        
                                        getline(inputFile, tempString, '#');
                                        tempInt = stoi(tempString);//stores the character as a integer
                                        //assign int to the proper boolean variable
                                        if(tempInt == 0)
                                        {
                                            heroArray[j].heroDanger = false;
                                        } else if(tempInt == 1)
                                        {
                                            heroArray[j].heroDanger = true;
                                        }
                                        getline(inputFile, tempString, '#');
                                        heroArray[j].rentTotal.heroCost = stof(tempString);//stores the cost as a float
                                        getline(inputFile, tempString, '#');
                                        heroArray[j].rentTotal.heroDamage = stof(tempString);//stores the damage cost as a float
                                        getline(inputFile, tempString, '#');
                                        heroArray[j].rentTotal.rentYears = stof(tempString);//stores the number of years as a float
                                        ++newHeroes;//indicates a new hero is added
                                        ++currHeroes;//increases because there is a new hero
                                        ++j;//next index for heroes array
                                    }
                                    
                                       
                                        
                                } 
                            }
                            
                            
                        } else 
                        {
                            //if unable to open file, this statement is outputed
                            cout << "\n" << fileName << " does not exist or is corrupt. Sorry. Can't load heroes.\n\n";
                        }
                        inputFile.close();
                        //indicate to the user how many heroes have been found and added to the heroes array
                        cout << "\n" << newHeroes << " heroes from " << fileName; 
                        cout << " have been added to your condo complex.";
                        break;
                    case 2:
                        //if option 2 is selected this line of code executes
                        for(int i = currHeroes; i < maxHeroes; ++i)
                        {
                            //repeats for every time a user wants to add another hero
                            while(goAgain)
                            {    
                                //gets needed information for hero and stores in the appropriate variable
                                cin.ignore();
                                cout << "\nSUPERHERO NAME: ";
                                getline(cin, heroArray[i].heroName);
                                cout << "\nDESCRIPTION: ";
                                getline(cin, heroArray[i].heroDescription);
                                tempChar = '0';//allows while loop to be entered
                                while(tempChar != 'y' && tempChar != 'n')
                                {
                                    cout << "\nIS IT A DANGEROUS HERO? (y or n): ";
                                    cin >> tempChar;
                                    //stores answer as a boolean variable
                                    if(tempChar == 'y')
                                    {
                                        heroArray[i].heroDanger = true;
                                    } else if(tempChar == 'n')
                                    {
                                        heroArray[i].heroDanger = false;
                                    }
                                }
    
                                cout << "\nHow much does " << heroArray[i].heroName;
                                cout << " pay for rent per month?\nRENT PRICE:  $";
                                cin >> heroArray[i].rentTotal.heroCost;
                                cout << "\nWhat is the typical cost of damage " ;
                                cout << heroArray[i].heroName << " has each month?\nDAMAGE COST:  $";
                                cin >> heroArray[i].rentTotal.heroDamage;
                                cout << "\nHow many years has " << heroArray[i].heroName;
                                cout << " lived in your condo?\nYEARS:  ";
                                cin >> heroArray[i].rentTotal.rentYears;
                                cout << "\nThe " << heroArray[i].heroName << " has been added";
                                ++currHeroes;//one more hero is added to the heroes array
                                ++newHeroes;//a new hero has been added
                                tempChar = '0';//allows while loop to be entered
                                while(tempChar != 'y' && tempChar != 'n')
                                {
                                    //asks user if they want to enter another hero
                                    cout << "\n\nWant to add more heroes? (y or n)  ";
                                    cin >> tempChar;
                                    if(tempChar == 'y')
                                    {
                                        goAgain = true;
                                    } else 
                                    {
                                        goAgain = false;
                                    }
                                }
                            }
                            
                            
                        } 
                        
                        break; 
               }
            }
        } while(choice < 1 || choice > 2);
    }

    

    return currHeroes;//number of current heroes is returned
}
/*
    Function Name: deleteHeroes()
    Parameters: an integer indicating the current number of heroes in the 
                Heroes array and the Heroes array.
    Returns: an integer indicating the current number of heroes
    Purpose: deletes a hero along with their information if found in the
             Heroes array.
*/
int deleteHeroes(int totalHeroes, Heroes heroArray[])
{
    string tempString;//temporary variable
    //outputs all of the hero's names stored in the array
    cout << "\nThe following is a list of all the heroes living in your condo complex:\n";
    for(int i = 0; i < totalHeroes; ++i)
    {
        cout << heroArray[i].heroName << endl;
    }
    cin.ignore();
    //asks user which one they want to delete
    cout << "\nWhich hero are you kicking out of your complex?\nSUPERHERO NAME:  ";
    getline(cin, tempString);

    //checks if hero can be removed
    if(moveArrayElement(totalHeroes, tempString, heroArray))
    {
        cout << "\nYou have removed " << tempString;
        --totalHeroes;//removed a hero so the current number of heroes decreases
    }else
    {
        cout << "\nSorry, a hero by the name " << tempString << " could not be found.";
    }
    return totalHeroes;//returns current number of heroes
}
/*
    Function Name: moveArrayElement()
    Parameters: an integer indicating the current number of heroes in the 
                Heroes array, a string containing the hero's name and the 
                Heroes array.
    Returns: a boolean if the hero was able to be delete
    Purpose: indicates if a hero was able to be deleted and shifts hero array
             elements accordingly
*/
bool moveArrayElement(int numHeroes, string heroesName, Heroes heroArray[])
{
    bool deleteHero = false;//can hero be deleted
    for(int i = 0; i < numHeroes; ++i)
    {
        if(heroesName == heroArray[i].heroName)
        {
            //if so moves over all array elements passed the deleted hero by 1
            for(int j = i; j < numHeroes; ++j)
            {
                heroArray[j].heroName = heroArray[j + 1].heroName;
                heroArray[j].heroDescription = heroArray[j + 1].heroDescription;
                heroArray[j].heroDanger = heroArray[j + 1].heroDanger;
                heroArray[j].rentTotal.heroCost = heroArray[j + 1].rentTotal.heroCost;
                heroArray[j].rentTotal.heroDamage = heroArray[j + 1].rentTotal.heroDamage;
                heroArray[j].rentTotal.rentYears = heroArray[j + 1].rentTotal.rentYears;
                deleteHero = true;
            }
        }
    }

    return deleteHero;//returns boolean
}
/*
    Function Name: printHeroes()
    Parameters: an integer indicating the current number of heroes in the 
                Heroes array and the Heroes array.
    Returns: None
    Purpose: Prints out the information about each hero.
*/
void printHeroes(int heroes, Heroes heroesArray[])
{
    string line(100, '-');//outputs a line of 100 dashes
    cout << fixed << showpoint << setprecision(2);//for decimals to be shown to the correct precision
    //outputs a description for all heroes
    for(int i = 0; i < heroes; ++i)
    {
        cout << line << endl; 
        cout << "\t\t\t\t\tSUPERHERO: " << i + 1 << endl;
        cout << setw(20) << setfill(' ');
        cout << setw(20) << left << "NAME:";
        cout << heroesArray[i].heroName << endl;
        cout << setw(20) << left << "DESCRIPTION:\n";
        cout << heroesArray[i].heroDescription << endl;
        cout << setw(20) << left << "DANGEROUS?";
        //converts boolean to an answer for the question
        if(heroesArray[i].heroDanger)
        {
            cout << "yes" << endl;
        }else
        {
            cout << "no" << endl;
        }
        cout << setw(20) << left << "RENT PRICE:";
        cout << "$" << heroesArray[i].rentTotal.heroCost << endl;
        cout << setw(20) << left << "DAMAGE COST:";
        cout << "$" << heroesArray[i].rentTotal.heroDamage << endl;
        cout << setw(20) << left << "YEARS:";
        cout << heroesArray[i].rentTotal.rentYears << endl << endl;
    }
}
/*
    Function Name: printRentDetails()
    Parameters: an integer indicating the current number of heroes in the 
                Heroes array and the Heroes array.
    Returns: None
    Purpose: Prints out the monthly rent and damage cost for each hero.
*/
void printRentDetails(int numHeroes, Heroes heroArray[])
{
    string line(100, '-');//prints 100 dashes
    float totalCost = 0;//intialized total cost to zero
    float totalDamage = 0;//intialized total damage cost to zero
    cout << fixed << showpoint << setprecision(2);//for decimal precision

    //outputs the header for the rent details
    cout << "\nRENT DETAILS OF EACH HERO:\n\n";
    cout << setw(30) << left << "SUPERHERO";
    cout << " " << setw(20) << right << "MONTHLY RENT";
    cout << "    " << setw(15) << left << "DAMAGE COST" << endl;
    //outputs information found in the heroes array
    for(int i = 0; i < numHeroes; ++i)
    {
        cout << setw(30) << left << heroArray[i].heroName;
        cout << "$" << setw(20) << right << heroArray[i].rentTotal.heroCost;
        cout << "   $" << setw(15) << right << heroArray[i].rentTotal.heroDamage << endl;
        totalCost += heroArray[i].rentTotal.heroCost;
        totalDamage += heroArray[i].rentTotal.heroDamage;
    }
    //outputs totals for each indicated value
    cout << line << endl << endl;
    cout << setw(30) << left << "TOTALS:";
    cout << "$" << setw(20) << right << totalCost;
    cout << "   $" << setw(15) << right << totalDamage;
}
/*
    Function Name: saveToFile()
    Parameters: an integer indicating the current number of heroes in the Heroes 
                array and the Heroes array. 
    Returns: None
    Purpose: Saves hero information to an output file if requested
*/
void saveToFile(int numHeroes, Heroes heroArray[])
{
    bool saveHeroes;//does the user want to save the file
    char choice;//user choice
    string fileName;//name of output file
    ofstream outputFile;//output file operator
    //validates answer
    while(choice != 'y' && choice != 'n')
    {
        //asks the user if they want to save the information in a file
        cout << "\nWould you like to save your superheroes list to a file? (y or n)  ";
        cin >> choice;
        //if yes prompts file name
        if(choice == 'y')
        {
            cout << "What is the name of the file you want to save your heroes to?\nFILENAME: ";
            cin.ignore();
            getline(cin, fileName);
            outputFile.open(fileName);
            /*if the file is able to be opened, it stores the information in the heroes array to
              the output file*/
            if(outputFile.is_open())
            {
                cout << "\nYour superheroes were successfully saved to the ";
                cout << fileName << " file.";
                cout << "\n\nGOODBYE!";
                for(int i = 0; i < numHeroes; ++i)
                {
                    outputFile << heroArray[i].heroName << "#";
                    outputFile << heroArray[i].heroDescription << "#";
                    if(heroArray[i].heroDanger)
                    {
                        outputFile << "1#";
                    }else
                    {
                        outputFile << "0#";
                    }
                    outputFile << heroArray[i].rentTotal.heroCost << "#";
                    outputFile << heroArray[i].rentTotal.heroDamage << "#";
                    outputFile << heroArray[i].rentTotal.rentYears << "#";
                }
            } else
            {
                //if the file was unable to open or found, the program outputs this statement
                cout <<"\nUnable to save your heroes to this file.";
                choice = 'a';
            }
            outputFile.close();
            


        }else
        {
            //if not outputs goodbye
            cout << "\n\nGOODBYE!";
        }

    }
}