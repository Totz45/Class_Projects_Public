/*
    File Name: Program_1.cpp
    Author: Tate Finley
    Date: February 7th, 2022
    Purpose: This program will determine the characteristics
             of a person based upon their answers to a series
             of questions given on the Personality Test.
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    bool runProgramAgain = true; //runs program again

    //loop will continue unless user inputs n or N for No   
    while(runProgramAgain)
    {
        char userAnswer; //holds user answer
        int introvert = 0; //variable for introvert
        int extrovert = 0; //variable for extrovert
        int positive = 0; //variable for positive person
        int negative = 0; //variable for negative person
        int serious = 0; //variable for serious
        int silly = 0; //variable for silly
        int spontaneous = 0; //variable for spontaneous
        int planner = 0; //variable for planner

        //writes out header aka personality test
        cout << "\n\n";
        cout << setfill('-') << setw(80) << "" << endl;
        cout << "\t\t\t\tPERSONALITY TEST\n";
        cout << setfill('-') << setw(80) << "" << endl;
        
        //gives purpose of program
        cout << "\nAnswer the following twelve questions to find\n";
        cout << "out your personality traits.\n\n";

        //first question: introvert vs extrovert
        cout << "\nIn a group discussing on a topic, I often find myself\n";
        cout << "\ta) Dominating the conversation\n";
        cout << "\tb) Pitching in here and there\n";
        cout << "\tc) Contributing a decent amount\n";
        cout << "\td) Saying one or two things\n";
        cout << "\te) Keeping quiet\n";
        cin >> userAnswer;

        //validate answer
        if (userAnswer < 'a' || userAnswer > 'e') {
            cout << "\nInvalid Answer please choose an answer from a-e,\n";
            cout << "Do Not use Uppercase letters.\n";
            cin >> userAnswer;
        }
    
        /*
            Answer formula for question 1
            Cases represent potential user answers
        */
        switch (userAnswer) {
            case 'a':
                extrovert = extrovert + 3;
                break;
            case 'b':
                extrovert = extrovert + 1;
                introvert = introvert + 1;
                break;
            case 'c':
                extrovert = extrovert + 2;
                break;
            case 'd':
                introvert = introvert + 2;
                break;
            case 'e':
                introvert = introvert + 3;
                break;
        }

        //second question: All-around
        cout << "\n\nWhen I get called on in class, I most likely will\n";
        cout << "\ta) Respond with a funny remark\n";
        cout << "\tb) Answer the question\n";
        cout << "\tc) Keep silent\n";
        cout << "\td) Say the first thing that comes to my mind\n";
        cout << "\te) Think, then respond\n";
        cin >> userAnswer;

        //validate answer
        if (userAnswer < 'a' || userAnswer > 'e') {
            cout << "\nInvalid Answer please choose an answer from a-e,\n";
            cout << "Do Not use Uppercase letters.\n";
            cin >> userAnswer;
        }
    
        //answer formula for question 2
        switch (userAnswer) {
            case 'a':
                silly = silly + 3;
                break;
            case 'b':
                serious = serious + 3;
                break;
            case 'c':
                introvert = introvert + 3;
                break;
            case 'd':
                spontaneous = spontaneous + 3;
                extrovert = extrovert + 1;
                break;
            case 'e':
                planner = planner + 3;
                break;
        }

        //third question: planner vs spontaneous
        cout << "\n\nYou are given an assignment that is due a week from now, ";
        cout << "when will you complete it?\n";
        cout << "\ta) Right Now\n";
        cout << "\tb) A couple days from now\n";
        cout << "\tc) Day just before the assignment is due\n";
        cout << "\td) The last day\n";
        cout << "\te) The last hour\n";
        cin >> userAnswer;

        //validate answer
        if (userAnswer < 'a' || userAnswer > 'e') {
            cout << "\nInvalid Answer please choose an answer from a-e,\n";
            cout << "Do Not use Uppercase letters.\n";
            cin >> userAnswer;
        }
    
        //answer formula for question 3
        switch (userAnswer) {
            case 'a':
                planner = planner + 5;
                break;
            case 'b':
                planner = planner + 3;
                break;
            case 'c':
                planner = planner + 1;
                break;
            case 'd':
                spontaneous = spontaneous + 3;
                break;
            case 'e':
                spontaneous = spontaneous + 5;
                break;
        }

        //fourth question: negative vs positive
        cout << "\n\nA glass of water is half filled, do you consider ";
        cout << "it to be?\n";
        cout << "\ta) Half Full\n";
        cout << "\tb) Half Empty\n";
        cout << "\tc) Just water\n";
        cin >> userAnswer;

        //validates answer
        if (userAnswer < 'a' || userAnswer > 'c') {
            cout << "\nInvalid Answer please choose an answer from a-c,\n";
            cout << "Do Not use Uppercase letters.\n";
            cin >> userAnswer;
        }
        
        //answer fomula for question 4
        switch (userAnswer) {
            case 'a':
                positive = positive + 2;
                break;
            case 'b':
                negative = negative + 2;
                break;
            case 'c':
                serious = serious + 3;
                break;
        }

        //fifth question: spontaneous vs planner
        cout << "\n\nYou have $500, how much do you spend?\n";
        cout << "\ta) The full $500\n";
        cout << "\tb) Spend until there is nothing I want\n";
        cout << "\tc) Save $100-$200 for later\n";
        cout << "\td) I am not spending anything\n";
        cin >> userAnswer;

        //validates answer
        if (userAnswer < 'a' || userAnswer > 'd') {
            cout << "\nInvalid Answer please choose an answer from a-d,\n";
            cout << "Do Not use Uppercase letters.\n";
            cin >> userAnswer;
        }

        //answer formula for question 5
        switch (userAnswer) {
            case 'a':
                spontaneous = spontaneous + 5;
                break;
            case 'b':
                spontaneous = spontaneous + 3;
                break;
            case 'c':
                planner = planner + 3;
                break;
            case 'd':
                planner = planner + 5;
                break;  
        }

        //sixth question: silly vs serious
        cout << "\n\nSelect a catchphrase.\n";
        cout << "\ta) Lets do this\n";
        cout << "\tb) Yeet\n";
        cout << "\tc) Imma go all out\n";
        cout << "\td) It's on like Donkey Kong\n";
        cin >> userAnswer;

        //validates answer
        if (userAnswer < 'a' || userAnswer > 'd') {
            cout << "\nInvalid Answer please choose an answer from a-d,\n";
            cout << "Do Not use Uppercase letters.\n";
            cin >> userAnswer;
        }
    
        //answer formula for question 6
        switch (userAnswer) {
            case 'a':
                serious = serious + 2;
                break;
            case 'b':
                silly = silly + 5;
                break;
            case 'c':
                serious = serious + 5;
                break;
            case 'd':
                silly = silly + 2;
                break;  
        }

        //seventh question: negative vs positive
        cout << "\n\nHow do you respond to someone if they win and";
        cout << " you lose?\n";
        cout << "\ta) Why are you so LUCKY?!\n";
        cout << "\tb) Good Game\n";
        cout << "\tc) Make up an excuse\n";
        cout << "\td) Acknowledge that they are better than you\n";
        cin >> userAnswer;

        //validates answer
        if (userAnswer < 'a' || userAnswer > 'd') {
            cout << "\nInvalid Answer please choose an answer from a-d,\n";
            cout << "Do Not use Uppercase letters.\n";
            cin >> userAnswer;
        }
    
        //answer formula for question 7
        switch (userAnswer) {
            case 'a':
                negative = negative + 5;
                break;
            case 'b':
                positive = positive + 3;
                break;
            case 'c':
                negative = negative + 3;
                break;
            case 'd':
                positive = positive + 5;
                break;  
        }

        //eigth question: introvert vs extrovert
        cout << "\n\nOn a scale of 1-10 how comfortable are you around";
        cout << " other people?\n";
        cout << "\ta) 1\n";
        cout << "\tb) 2-4\n";
        cout << "\tc) 5-7\n";
        cout << "\td) 8-9\n";
        cout << "\te) 10\n";
        cin >> userAnswer;

        //validates answer
        if (userAnswer < 'a' || userAnswer > 'e') {
            cout << "\nInvalid Answer please choose an answer from a-e,\n"; 
            cout << "Do Not use Uppercase letters.\n";
            cin >> userAnswer;
        }
    
        //answer formula for question 8
        switch (userAnswer) {
            case 'a':
                introvert = introvert + 5;
                break;
            case 'b':
                introvert = introvert + 3;
                break;
            case 'c':
                introvert = introvert + 1;
                break;
            case 'd':
                extrovert = extrovert + 3;
                break;
            case 'e':
                extrovert = extrovert + 5;
                break;  
        }
        
        //ninth question: silly vs serious
        cout << "\n\nIn a friend group are you the\n";
        cout << "\ta) Comedic Relief\n";
        cout << "\tb) Casual\n";
        cout << "\tc) Contributor\n";
        cin >> userAnswer;

        //validates answer
        if (userAnswer < 'a' || userAnswer > 'c') {
            cout << "\nInvalid Answer please choose an answer from a-c,\n";
            cout << "Do Not use Uppercase letters.\n";
            cin >> userAnswer;
        }
    
        //answer formula for question 9
        switch (userAnswer) {
            case 'a':
                silly = silly + 3;
                break;
            case 'b':
                serious = serious + 1;
                silly = silly + 1;
                break;
            case 'c':
                serious = serious + 3;
                break;
        }

        //tenth question: negative vs positive and introvert vs extrovert
        cout << "\n\nHow do you view society \n";
        cout << "\ta) Cruel and crowded\n";
        cout << "\tb) Cruel and lonely\n";
        cout << "\tc) A nice mix of people\n";
        cout << "\td) A nice absense of people\n";
        cin >> userAnswer;

        //validates answer
        if (userAnswer < 'a' || userAnswer > 'd') {
            cout << "\nInvalid Answer please choose an answer from a-d,\n";
            cout << "Do Not use Uppercase letters.\n";
            cin >> userAnswer;
        }
    
        //answer formula for question 10
        switch (userAnswer) {
            case 'a':
                negative = negative + 2;
                introvert = introvert + 2;
                break;
            case 'b':
                negative = negative + 2;
                extrovert = extrovert + 2;
                break;
            case 'c':
                positive = positive + 2;
                extrovert = extrovert + 2;
                break;
            case 'd':
                positive = positive + 2;
                introvert = introvert + 2;
                break;
        }

        //eleventh question: negative vs positive
        cout << "\n\nYou get a C on a test, what is your reaction\n";
        cout << "\ta) This is fine\n";
        cout << "\tb) Aw yeah a C\n";
        cout << "\tc) I should improve next time\n";
        cout << "\td) This is a death sentence to passing this class\n";
        cin >> userAnswer;

        //validates answer
        if (userAnswer < 'a' || userAnswer > 'd') {
            cout << "\nInvalid Answer please choose an answer from a-d,\n";
            cout << "Do Not use Uppercase letters.\n";
            cin >> userAnswer;
        }
    
        //answer formula for question 11
        switch (userAnswer) {
            case 'a':
                positive = positive + 2;
                break;
            case 'b':
                positive = positive + 4;
                break;
            case 'c':
                negative = negative + 2;
                break;
            case 'd':
                negative = negative + 4;
                break;
        }

        //twelfth question: planner vs spontaneous and serious vs silly
        cout << "\n\nA friend invites you to a party, but you are\n";
        cout << " trying to finish a resume, what do you respond\n";
        cout << "\ta) No, I have work to do\n";
        cout << "\tb) I have some time\n";
        cout << "\tc) Let me finish then I'll come\n";
        cout << "\td) I could write my resume later\n";
        cout << "\te) Let's celebrate\n";
        cin >> userAnswer;

        //validates answer
        if (userAnswer < 'a' || userAnswer > 'e') {
            cout << "\nInvalid Answer please choose an answer from a-e,\n";
            cout << "Do Not use Uppercase letters.\n";
            cin >> userAnswer;
        }
    
        //answer formula for question 12
        switch (userAnswer) {
            case 'a':
                serious = serious + 5;
                break;
            case 'b':
                silly = silly + 3;
                spontaneous = spontaneous + 3;
                break;
            case 'c':
                planner = planner + 5;
                serious = serious + 3;
                break;
            case 'd':
                planner = planner + 3;
                break;
            case 'e':
                spontaneous = spontaneous + 5;
                silly = silly + 5;
                break;  
        }

        //print results 
        cout << "\n\t\t\t\tRESULTS\n";
        cout << setfill('-') << setw(80) << "" << endl;

        //final calculation and verdict, extrovert vs introvert
        if (introvert > extrovert) {
            cout << "You are an introvert.\n";
        } else if (introvert < extrovert) {
            cout << "You are an extrovert.\n";
        } else {
            cout << "You are not an extrovert or an introvert\n";
        }
        
        //final calculation and verdict, positive or negative person
        if (positive > negative) {
            cout << "You are a positive person.\n";
        } else if (positive < negative) {
            cout << "You are a negative person.\n";
        } else {
            cout << "You are not a positive or negative person\n";
        }
        
        //final calculation and verdict, silly vs serious
        if (silly > serious) {
            cout << "You are silly.\n";
        } else if (silly < serious) {
            cout << "You are serious.\n";
        } else {
            cout << "You are neither silly or serious\n";
        }

        //final calculation and verdict, spontaneous vs planner
        if (spontaneous > planner) {
            cout << "You are a spontaneous person.\n";
        } else if (spontaneous < planner) {
            cout << "You are a planner.\n";
        } else {
            cout << "You are not spontaneous or a planner.\n";
        }

        //end results
        cout << setfill('-') << setw(80) << "" << endl;

        //ask user if they want to run the program again 
        cout << "\nWould you like to take the Personality Test again? Answer y or n\n";
		cin >> userAnswer;

        /*
            if n or N, ends program
            if y, Y, or any other character, restarts program in a loop
        */
        if (userAnswer == 'n' || userAnswer == 'N') {
            runProgramAgain = false;
        }


    }
    

    return 0;
}
