/* 
PROBLEM STATEMENT : Find a peak element which is not smaller than its neighbours

Given an array arr of n elements that is first strictly increasing and then maybe strictly decreasing, find the maximum element in the array.

Note: If the array is increasing then just print the last element will be the maximum value.

The following corner cases give a better idea about the problem. 

1. If the input array is sorted in a strictly increasing order, the last element is always a peak element. For example, 50 is peak element in {10, 20, 30, 40, 50}.
2. If the input array is sorted in a strictly decreasing order, the first element is always a peak element. 100 is the peak element in {100, 80, 60, 50, 20}.
3. If all elements of the input array are the same, every element is a peak element.

It is clear from the above examples that there is always a peak element in the input array.
*/

/*
SOLUTION :
METHOD 1 : Normal Approach
Time complexity : O(n)
Space Complexity : O(1)

METHOD 2 : Using Recursive Binary Search 
Time complexity : O(log n)
Space Complexity : O(log n), as recursive call is there, hence implicit stack is used.

METHOD 3 : Using Iterative Binary Search
Time complexity : O(log n)
Space Complexity : O(1)
*/
#include <iostream>
using namespace std;

int findPeak(int arr[], int n)
{
    // sorted in descending order
    if(arr[0] >= arr[1])
        return arr[0];
    
    // sorted in ascending order
    if(arr[n-1] >= arr[n-2])
        return arr[n-1];

    // unsorted array
    for(int i = 1; i < n-1; i++)
    {
        if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1]) //to avoid segmentation error (or use if else if)
            return arr[i];
    }
}

int RecursiveBinaryPeak(int arr[], int n, int low, int high)
{
    int mid = low + (high - low) / 2;
    while(low <= high)
    {
        if(mid == 0 || arr[mid] >= arr[mid + 1] && arr[mid] <= arr[mid - 1] || mid == n-1 && arr[mid] >= arr[mid - 1])
            return mid;

        else if(arr[mid] < arr[mid-1])
            return RecursiveBinaryPeak(arr, n, 0, mid-1);

        else
            return RecursiveBinaryPeak(arr, n, mid+1, n-1);
    }
}

int main()
{
    //unsorted array
    int arr[] = {5, 10, 20, 15};
    int n = sizeof(arr)/sizeof(int);
    int peak = RecursiveBinaryPeak(arr, n, 0 , n-1);
    cout<<"Peak element is "<<peak<<endl;

    //ascending order
    int arr1[] = {10, 20, 30, 40, 50};
    int n1 = sizeof(arr1)/sizeof(int);
    int peak1 = RecursiveBinaryPeak(arr1, n1, 0, n1-1);
    cout<<"Peak element is "<<peak1<<endl;

    //descending order
    int arr2[] = {100, 80, 60, 50, 20};
    int n2 = sizeof(arr2)/sizeof(int);
    int peak2 = RecursiveBinaryPeak(arr2, n2, 0, n2-1);
    cout<<"Peak element is "<<peak2<<endl;

    //equal elements
    int arr3[] = {10, 10, 10, 10, 10};
    int n3 = sizeof(arr3)/sizeof(int);
    int peak3 = RecursiveBinaryPeak(arr3, n3, 0, n3-1);
    cout<<"Peak element is "<<peak3<<endl;
}

