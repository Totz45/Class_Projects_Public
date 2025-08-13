/*
    File Name: Lab9b.cpp
    Author: Tate Finley
    Date: March 30th, 2022
    Purpose: This program uses a sorting algorithm to rearrange indexes in a vector.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> setValue{ 7, 4, 36, 1, 3, 6, 2, 99, 77, 10, }; //intializes vector with 10 elements
    int i, j, min, temp; //variables used for algorithm
    int total; //running total that adds each element in setValue vector 
    
    //multiplies each element in setValue vector by 2
    for(i = 0; i < setValue.size(); ++i)
    {
        setValue.at(i) *= 2;
    }

    cout << "\nThe vector elements, multiplied by 2, are: ";
    
    //outputs multiplied values
    for(i = 0; i < setValue.size(); ++i)
    {
        cout << setValue.at(i) << " ";
    }

    total = setValue.at(0);//intialized to first element in vector
    
    //adds each element to the variable total
    for(i = 1; i < setValue.size(); ++i)
    {
        total += setValue.at(i);
    }

    //outputs total of all vectors
    cout << "\n\nThe total of all array elements is " << total << endl;

    //ALGORITHM: SelectionSort(setValue.at(0,...,n-1))
    //Purpose: Sorts given vector by selection sort
    //Input: A vector setValue of orderable elements
    //Output: A vector setValue sorted in ascending order
    
    for (i = 0; i < setValue.size() - 1; ++i)
    {
        //find the next minimum value in the vector
        min = i;
        for (j = i + 1; j < setValue.size(); ++j) 
        {
            if(setValue.at(j) < setValue.at(min))
            {
                min = j;
            }
        }
        //swap the current vector item with the minimum element
        temp = setValue.at(i);
        setValue.at(i) = setValue.at(min);
        setValue.at(min) = temp;
    }
        
    cout << "\nThe sorted vector elements are: ";

    //outputs each element/number in increasing order
    for(i = 0; i < setValue.size(); ++i)
    {
        cout << setValue.at(i) << " ";
    }

    return 0;
}