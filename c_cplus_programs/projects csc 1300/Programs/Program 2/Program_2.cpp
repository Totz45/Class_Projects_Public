/*
    File Name: Program_2.cpp
    Author: Tate Finley
    Date: 2/26/22
    Purpose: This program recreates the game of MASH using menu based programs,
             switch statements, using loops to validate input, using loops to 
             allow a program to run again, functions, and cin/getline().
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int displayMenuGetChoice();
string displayJobChoice();
string displayCompanyChoice();
int displaySalaryChoice();

int main()
{
    //boolean function allows do-while loop to be completed
    bool playAgain = true;
    
    //program runs at least once before it can loop or end the program
    do{
        int userChoiceMain; //either ends the program, or begins mash depending on user selection
        string name1; //person user likes
        string name2; //other person user likes
        string name3; //person user hates
        string town1; //town user likes
        string town2; //other town user likes
        string town3; //town user hates
        string selectedJob; //randomly selected job from three user inputs
        string selectedCompany; //randomly selected company from three user inputs
        string car1; //car model user likes
        string car2; //other car model user likes
        string car3; //car model user hates
        
        //allows choice to be transfered into main function
        userChoiceMain = displayMenuGetChoice();
        
        switch(userChoiceMain) 
        {
             //if option is 1, runs mash
            case 1:
                int numSmall1; //first number from 1-100
                int numSmall2; //second number from 1-100
                int numSmall3; //third number from 1-100
                int selectedNumLarge; //randomly selected number from three user inputed numbers

                cout << "You chose to play MASH\n";
                
                //Three questions to obtain user inputs for people they like/dislike
                cout << "\nEnter in a person that you like: ";
                cin.ignore(); //used because there was a cin function executed before this getline
                getline(cin, name1); //used to obtain inputed string

                cout << "Enter in another person that you like: ";
                getline(cin, name2);

                cout << "Enter in a person that you hate: ";
                getline(cin, name3);

                //user inputs three numbers from 1-100
                cout << "\nEnter three numbers between 1 and 100, separated by a space.\n";
                cin >> numSmall1 >> numSmall2 >> numSmall3;

                //three while loops to validate each answer
                while(numSmall1 < 1 || numSmall1 > 100) 
                {
                    cout << "The first number is invalid"; 
                    cout << " please enter a number between 1 and 100.\n";
                    cin >> numSmall1;
                }
                while(numSmall2 < 1 || numSmall2 > 100) 
                {
                    cout << "The second number is invalid"; 
                    cout << " please enter a number between 1 and 100.\n";
                    cin >> numSmall2;
                }
                while(numSmall3 < 1 || numSmall3 > 100) 
                {
                    cout << "The third number is invalid"; 
                    cout << " please enter a number between 1 and 100.\n";
                    cin >> numSmall3;
                }

                //three questions to obtain user's favorite/least favorite city, states
                cout << "\nEnter in one city, state that you like: ";
                cin.ignore(); //cin statements occur before this getline
                getline(cin, town1); //allows spaces within a string

                cout << "Enter in another city, state that you like: ";
                getline(cin, town2);

                cout << "Enter in one city, state that you hate: ";
                getline(cin, town3);

                /*assigns selectedJob with the random output from 
                  displayJobChoice() */
                selectedJob = displayJobChoice();

                /*assigns selectedCompany with the random output from 
                  displayCompanyChoice() */
                selectedCompany = displayCompanyChoice();

                /*assigns selectedNumLarge with the random output from 
                  displaySalaryChoice() */
                selectedNumLarge = displaySalaryChoice();

                //three questions to obtain user's favorite/least favorite car or car model
                cout << "\nEnter in a car that you like: ";
                cin.ignore(); //cin statements occur before this getline
                getline(cin, car1); //includes spaces if user puts spaces in a string

                cout << "Enter in another car that you like: ";
                getline(cin, car2);

                cout << "Enter in a car that you hate: ";
                getline(cin, car3);

                srand(time(0)); //seeded with time to ensure each output is different

                //prints out mash results
                cout << endl;
                cout << setfill('*') << setw(7) << " ";
                cout << "MASH RESULTS " << setfill('*') << setw(7) << " ";
                cout << endl;

                /*decides whether the user will live in a mansion, 
                  apartmant, shack, or house */
                switch(rand() % 4 + 1) 
                {
                    case 1:
                        cout << "You will live in a luxurious mansion.\n";
                        break;
                    case 2:
                        cout << "You will live in a crammed apartment.\n";
                        break;
                    case 3:
                        cout << "You will live in a old rusty shack.\n";
                        break;
                    case 4:
                        cout << "You will live in a decently sized house.\n";
                        break;
                }

                //decides which name to output
                switch(rand() % 3 + 1) 
                {
                    case 1:
                        cout << "You will be happily married to " << name1 << ".\n";
                        break;
                    case 2:
                        cout << "You will be happily married to " << name2 << ".\n";
                        break;
                    case 3:
                        cout << "You will be happily married to " << name3 << ".\n";
                        break;
                } 
                
                //decides which number from 1-100 to output
                switch(rand() % 3 + 1) 
                {
                    case 1:
                        cout << "You and your spouse will have " << numSmall1 << " children.\n";
                        break;
                    case 2:
                        cout << "You and your spouse will have " << numSmall2 << " children.\n";
                        break;
                    case 3:
                        cout << "You and your spouse will have " << numSmall3 << " children.\n";
                        break;
                } 

                //decides which town to output
                switch(rand() % 3 + 1) 
                {
                    case 1:
                        cout << "You will live in " << town1 << ".\n";
                        break;
                    case 2:
                        cout << "You will live in " << town2 << ".\n";
                        break;
                    case 3:
                        cout << "You will live in " << town3 << ".\n";
                        break;
                }

                //statement based on the randomly selected company, job, and numLarge/salary
                cout << "You will work at " << selectedCompany << " as a ";
                cout << selectedJob << " making $" << selectedNumLarge << " a year.\n";

                //decides which car model to output
                switch(rand() % 3 + 1) 
                {
                    case 1:
                        cout << "You will drive a " << car1 << ".\n";
                        break;
                    case 2:
                        cout << "You will drive a " << car2 << ".\n";
                        break;
                    case 3:
                        cout << "You will drive a " << car3 << ".\n";
                        break;
                }
                //after break continues do-while loop until option 2 is selected
                break;
             //if option is 2, ends program and stops do-while loop
            case 2:
                cout << "You chose to end the program\n";
                cout << "Goodbye!\n";
                playAgain = false; //allows loop to be stopped
                break;
        } 
    } while (playAgain);

    return 0;
}
/*
    Function Name: displayMenuGetChoice()
    Function Returns: the integer, userChoice, in the form of either 1 or 2
    Function Purpose: This function serves as the menu for this program. 
                      It validates the user input to be one of the two
                      options.
*/
int displayMenuGetChoice() 
{
    int userChoice; //user's option to be validated

    //menu for program
    cout << "\n\nHere are the options\n";
    cout << "\t1) Play MASH\n";
    cout << "\t2) End the program\n";
    cout << "Which option do you choose\n";
    cin >> userChoice;

    //loop validating input, 1 and 2 are valid inputs
    while (userChoice < 1 || userChoice > 2)
    {
        cout << "Invalid input, please choose 1 or 2\n";
        cin >> userChoice;
    }
    
    //gives displayMenuGetChoice its variable
    return userChoice;
}
/*
    Function Name: displayJobChoice()
    Function Returns: One of the three randomly determined strings the user
                      inputs.
    Function Purpose: This function is used to allow the user to input  
                      two of their favorite jobs as well as a hated job.
                      Then it randomly picks one of the three answers and
                      returns it to the function.
*/
string displayJobChoice()
{
    string dreamJob1st; //user's most desired job
    string dreamJob2nd; //user's second most desired job
    string nightmareJob; //user's most despised job
    int randNum1; //randomizes and picks one of either

    srand(time(0)); //seeded with time to ensure each output differs

    /*user responds to three questions, getline is used because 
      the variable is a string */
    cout << "\nEnter in your dream job: ";
    getline(cin, dreamJob1st);

    cout << "Enter in your 2nd dream job: ";
    getline(cin, dreamJob2nd);

    cout << "Enter in your nightmare job: ";
    getline(cin, nightmareJob);

    /*set randNum1 to a random number from 1-3, used an if else 
      statement to randomize which string is returned */
    randNum1 = rand() % 3 + 1;
    
    if(randNum1 == 1)
    {
        return dreamJob1st;
    } else if(randNum1 == 2)
    {
        return dreamJob2nd;
    } 
    else{
        return nightmareJob;
    }
            
}
/*
    Function Name: displayCompanyChoice()
    Function Returns: One of the three randomly determined strings the user
                      inputs.
    Function Purpose: This function is used to allow the user to input  
                      two of their favorite companies/restaurants as well as
                      their least favorite company/restaurant. Then it randomly 
                      picks one of the three answers and returns it to the 
                      function.
*/
string displayCompanyChoice()
{
    string dreamCompany1st; //user's favorite company/restaurant
    string dreamCompany2nd; //user's second pick for favorite company/restaurant
    string nightmareCompany; //company/restaurant the user hates
    int randNum2; //randomizes and picks one of either

    srand(time(0)); //seeded with time to ensure each output differs

    /*user responds to three questions, getline is used because 
      the variable is a string */
    cout << "\nEnter in a company or restaurant you like: ";
    getline(cin, dreamCompany1st);

    cout << "Enter in another company or restaurant you like: ";
    getline(cin, dreamCompany2nd);

    cout << "Enter in a company or restaurant you hate: ";
    getline(cin, nightmareCompany);

    /*set randNum2 to a random number from 1-3, used an if else 
      statement to randomize which string is returned */
    randNum2 = rand() % 3 + 1;
    
    if(randNum2 == 1)
    {
        return dreamCompany1st;
    } else if(randNum2 == 2)
    {
        return dreamCompany2nd;
    } 
    else{
        return nightmareCompany;
    }
}
/*
    Function Name: displaySalaryChoice()
    Function Returns: One of the three randomly determined numbers the user
                      inputs.
    Function Purpose: This function is used to allow the user to input  
                      three numbers from 10,000 to 500,000 and validates the
                      input. Then it randomly picks one of the three numbers  
                      and returns it to the function.
*/
int displaySalaryChoice()
{
    int numLarge1; //first number 10000-500000
    int numLarge2; //second number 10000-500000
    int numLarge3; //third number 10000-500000
    int randNum3; //randomizes and picks one of either numLarge1, numLarge2, or numLarge3

    srand(time(0)); //seeded with time to ensure each output differs
    
    //user responds to statement with three cin inputs
    cout << "\nEnter three numbers between 10000 and 500000 separated by a space.\n";
    cin >> numLarge1 >> numLarge2 >> numLarge3;

    //while loop to validate first input
    while(numLarge1 < 10000 || numLarge1 > 500000) 
    {
        cout << "The first number is invalid"; 
        cout << " please enter a number between 10000 and 500000.\n";
        cin >> numLarge1;
    }
    //while loop to validate second input
    while(numLarge2 < 10000 || numLarge2 > 500000) 
    {
        cout << "The second number is invalid"; 
        cout << " please enter a number between 10000 and 500000.\n";
        cin >> numLarge2;
    }
    //while loop to validate third input
    while(numLarge3 < 10000 || numLarge3 > 500000) 
    {
        cout << "The third number is invalid"; 
        cout << " please enter a number between 10000 and 500000.\n";
        cin >> numLarge3;
    }

    /*set randNum3 to a random number from 1-3, used an if else 
      statement to randomize which number is returned */
    randNum3 = rand() % 3 + 1;
    
    if(randNum3 == 1)
    {
        return numLarge1;
    } else if(randNum3 == 2)
    {
        return numLarge2;
    } 
    else{
        return numLarge3;
    }
}