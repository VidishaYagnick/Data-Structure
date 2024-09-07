/*
Count number of occurrences (or frequency) in a sorted array :  
Given a sorted array arr[] of size N and a number X, you need to find the number of occurrences of X in given array.
*/

#include<iostream>
using namespace std;

int getFirstOcc(int arr[], int low, int high, int x)
{
    if(low <= high)
    {
        int mid = low + (high - low) / 2;

        if((mid == 0 || arr[mid - 1] < x) && arr[mid] == x) //Note
            return mid;
        
        else if(arr[mid] < x)
            return getFirstOcc(arr, mid + 1, high, x);

        else
            return getFirstOcc(arr, low, mid - 1, x);
    }
    return -1;
}

int getLastOcc(int arr[], int n, int low, int high, int x)
{
    if(low <= high)
    {
        int mid = low + (high - low) / 2;

        if((mid == n-1 || arr[mid + 1] > x) && arr[mid] == x) //Note
            return mid;

        else if(arr[mid] > x)
            return getLastOcc(arr, n, low, mid - 1, x);

        else
            return getLastOcc(arr, n, mid + 1, high, x);
    }

    return 0;
}

int getFrequency(int arr[], int n, int x)
{
    // Find the first occurrence of the element
    int First = getFirstOcc(arr, 0, n - 1, x);

    // If the element does not exist, return -1
    if (First == -1)
        return -1;

    // Find the first occurrence of the element
    int Last = getLastOcc(arr, n, First, n-1, x); //Note

     // Return the difference between the last and first occurrences + 1 to get the total count
    return (Last - First) + 1;
}

int main()
{
    int n,x;
    cout<<"Enter the size of array ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array ";
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element to find its occurence ";
    cin>>x;

    cout<<"Number of occurence of the value is "<<getFrequency(arr, n, x);

}

// Time complexity : O(log n)
// Space complexity : O(n)