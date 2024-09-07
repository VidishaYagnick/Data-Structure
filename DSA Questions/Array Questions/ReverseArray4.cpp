/*
4. Array Reverse Recursion (In-place or Non In-place):
a. Define a recursive function that takes an array as input.
b. Swap the first and last elements.
c. Recursively call the function with the remaining subarray.
*/

#include<iostream>
using namespace std;

/* Function to reverse arr[] from start to end*/
void reverseArray(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursive Function calling
    reverseArray(arr, start + 1, end - 1);
}

/* Utility function to print an array */
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };

    // To print original array
    printArray(arr, 6);

    // Function calling
    reverseArray(arr, 0, 5);

    cout << "Reversed array is" << endl;

    // To print the Reversed array
    printArray(arr, 6);

    return 0;
}

// Time complexity : O(n)
// Space complexity : O(n)