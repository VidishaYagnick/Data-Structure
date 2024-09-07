/* 
1. Array Reverse Using an Extra Array (Non In-place):
a. Create a new array of the same size as the original array.
b. Copy elements from the original array to the new array in reverse order.
*/

#include<iostream>
using namespace std;

void reverseArray(int arr[], int n)
{
    int reverse[n];
    for(int i = 0; i < n; i++)
    {
        reverse[i] = arr[n-i-1];
    }
    
    // Print reversed array
    for(int i = 0; i < n; i++)
    {
        cout<<reverse[i]<<" ";
    }
}
int main()
{
    int arr[] = { 10, 20, 30, 40, 50 };
    int n = sizeof(arr) / sizeof(int);

    reverseArray(arr,n);
}
// Time complexity : O(n)
// Space complexity : O(n)

