/*
K’th Smallest Element in Unsorted Array : 
Given an array arr[] of N distinct elements and a number K, where K is smaller than the size of the array. Find the K’th smallest element and largest element in the given array.
*/

//1. Using Sorting – O(n log(n)) time and O(1) auxiliary space:

#include<iostream>
#include<algorithm>
using namespace std;

void kthSmallestAndLargest(int arr[], int n, int k)
{
    // Sort the given array
    sort(arr, arr + n);

    cout<<"kth smallest number is "<<arr[k-1]<<endl;

    cout<<"kth largest number is "<<arr[n-k];
}

int main()
{
    int n, k;
    cout<<"Enter the size of array ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array ";
    for(int i=0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the value of k: ";
    cin>>k;

    kthSmallestAndLargest(arr,n,k);

    return 0;
}

// Time complexity : O(n log n)
// Space Complexity : O(1)