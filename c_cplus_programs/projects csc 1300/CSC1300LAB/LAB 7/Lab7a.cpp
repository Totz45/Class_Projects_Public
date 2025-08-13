/*
    File Name: Lab7a.cpp
    Author: Tate Finley
    Date: 3/10/22
    Purpose: This program uses functions in order to calculate
             the cumulative amount of days the employees were sick 
             for.
*/

#include <iostream>
using namespace std;

int DisplayMenuGetChoice();
void EmployeeSickDays();

int main() 
{
    bool runProgram = true; //allows program to repeat after case 1

    //iterates at least once 
    do {
        int userChoice;//user's choice in this function

        //assigns returned value as userChoice
        userChoice = DisplayMenuGetChoice();
        //which then allows this switch to execute
        switch (userChoice)
        {
            //runs if option 1 is selected
            case 1:
                EmployeeSickDays();
                break;
            //runs if option 2 is selected
            case 2:
                //end program statement
                cout << "\nBye!";
                runProgram = false; //allows user to exit loop and end program
                break;
        }
    } while(runProgram);

    return 0;
}
/*
    Function Name: DisplayMenuGetChoice()
    Function Parameters: int menuChoice that has no arguments
    Function Returns: menuChoice which is assigned to userChoice.
    Function Purpose: This function prints out the menu for the main 
                      function and validates answer before returning
                      the selected choice.
*/
int DisplayMenuGetChoice()
{
    int menuChoice; //input variable for choice

    //main menu
    cout << "\n\nWELCOME TO THE BANK!";
    cout << "\nPlease choose one of the following options:";
    cout << "\n\t1 - Enter Employee Days";
    cout << "\n\t2 - End the Program\n\n";
    cout << "CHOICE: ";
    cin >> menuChoice;

    //validates answer
    while(menuChoice < 1 || menuChoice > 2) 
    {
        cout << "Invalid choice.  Please choose 1 or 2.\n";
        cout << "CHOICE: ";
        cin >> menuChoice;
    }

    //returns user's selected choice after validation
    return menuChoice;
}
/*
    Function Name: EmployeeSickDays()
    Function Parameters: no parameters or arguments
    Function Returns: void function so it does not return anything
    Function Purpose: This function is used to run option 1 of the program.
                      It asks the manager how many employees, and the number
                      of sick days per employee per year using a nested for loop.
*/
void EmployeeSickDays()
{
    int numEmployees; //number of employees
    int sickDays; //number of sick days per employee
    int totalSickDays; //running total of sickDays
    int i; //initialization variable for outer loop
    int j; //initialization variable for inner loop
    
    //main input for number of employees, determines number of iterations in outer for loop.
    cout << "How many Employees worked at the Bank during each of the last three years?\n";
    cin >> numEmployees;

    //initialization of running total
    totalSickDays = 0;

    //for loop set to iterate the value set for numEmployee
    for(i = 0; i < numEmployees; ++i) 
    {
        /*since the question asks about the last three years,
          the inner loop will iterate three times, one per year*/
        for(j = 0; j < 3; ++j) {
            cout << "How many sick days was Employee " << i + 1; //i + 1 for employee number
            cout << " out for, during year " << j + 1 <<  " ? "; //j + 1 for year number
            cin >> sickDays;
            totalSickDays += sickDays; //accumulator          
        }
    }

    //outputs the total number of employees and the sum of all the sick days over all employees.
    cout << "\n\nThe " << numEmployees << " Employees were out sick for a total of ";
    cout << totalSickDays << " days during the last 3 years";
    
}