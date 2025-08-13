/*
  File Name: sort.h
  Author: Tate Finley
  Date: 9/13/22
  Purpose: Demonstrate the efficiency of different sorting algorithms.
*/
#ifndef SORT_H
#define SORT_H

/*
  Function name: bubbleSort()
  Function Purpose: uses the algorithm of bubble sort to sort an array.
                    Bubble sort compares two elements next to each other
                    and swaps them if needed. 
  Parameters: a pointer preferably an array and an integer
  Returns: None
*/
void bubbleSort (int* arr, int n)
{
  int swapArr;//temporary variable
  for (int i = 0; i < n - 1; i++){
    for (int j = 0; j < n - i - 1; j++){
      if(arr[j] > arr[j + 1]){
        swapArr = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = swapArr;
      }
      //the largest element of the remaining unsorted will be sorted by now
    }
  }
}

/*
  Function name: insertionSort()
  Function Purpose: uses the algorithm of insertion sort to sort an array.
                    Insertion sort builds the array one element at a time;
                    If an element is out of place it inserts it to the 
                    right spot. 
  Parameters: a pointer preferably an array and an integer
  Returns: None
*/
void insertionSort (int* arr, int n)
{
  int key; //item that is to be sorted
  int position; //place where key is to be inserted into array

  for(int i = 0; i < n; i++){
    key = arr[i];
    position = i - 1;
    while(position >= 0 && arr[position] > key){
      arr[position + 1] = arr[position];
      position = position - 1;
    }
    arr[position + 1] = key;
    //variable at i is inserted/sorted
  }
}

/*
  Function name: partition()
  Function Purpose: this function is used to separate the array into smaller and
                    smaller pieces while also sorting them.
  Parameters: a pointer preferably an array and two integers
  Returns: an integer
*/
int partition (int* arr, int left, int right)
{
  int key;//
  int tempVar;//
  key = arr[left];
  int l1 = left-1;
  int r1 = right+1;
  //will continue sorting until smallest number in array
  while(l1 < r1){
    do{
      r1--;
    }while(arr[r1] > key);
    do{
      l1++;
    }while(arr[l1] < key);
    if(l1 < r1)
    {
      tempVar = arr[l1];
      arr[l1] = arr[r1];
      arr[r1] = tempVar;
    }
    
  }
  return r1;
}
/*
  Function name: quickSort()
  Function Purpose: uses the algorithm of quick sort to sort an array.
                    Quick sort uses partition function to separate large
                    elements from small ones then recursion is used to
                    sort the subdivisions(partitions) it creates. 
  Parameters: a pointer preferably an array and two integers
  Returns: None
*/
void quickSort (int* arr, int low, int high)
{
  int keyLocation = 0;
  //if statement indicates if a partition has been sorted
  if(low >= high) {
    return;
  }
  keyLocation = partition(arr, low, high);//returns last element in low partition
  quickSort(arr, low, keyLocation);//sorts low partition
  quickSort(arr, keyLocation + 1, high);//sorts high partition
}

//don't touch this, it's here to plug the function into the visualizer
void quickSort (int* arr, int n)
  { quickSort(arr, 0, n-1); }

#endif