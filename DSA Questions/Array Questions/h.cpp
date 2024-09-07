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
        if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1])
            return arr[i];
    }
    return -1; // In case no peak is found, which shouldn't happen in a valid input
}

int RecursiveBinaryPeak(int arr[], int n, int low, int high)
{
    if (low == high)
        return low;

    int mid = low + (high - low) / 2;

    if (mid > 0 && arr[mid] < arr[mid - 1])
        return RecursiveBinaryPeak(arr, n, low, mid - 1);
    else if (mid < n-1 && arr[mid] < arr[mid + 1])
        return RecursiveBinaryPeak(arr, n, mid + 1, high);
    else
        return mid;
}

int main()
{
    //unsorted array
    int arr[] = {5, 10, 20, 15};
    int n = sizeof(arr)/sizeof(int);
    int peak = RecursiveBinaryPeak(arr, n, 0 , n-1);
    cout<<"Peak element index is "<<peak<<", value is "<<arr[peak]<<endl;

    //ascending order
    int arr1[] = {10, 20, 30, 40, 50};
    int n1 = sizeof(arr1)/sizeof(int);
    int peak1 = RecursiveBinaryPeak(arr1, n1, 0, n1-1);
    cout<<"Peak element index is "<<peak1<<", value is "<<arr1[peak1]<<endl;

    //descending order
    int arr2[] = {100, 80, 60, 50, 20};
    int n2 = sizeof(arr2)/sizeof(int);
    int peak2 = RecursiveBinaryPeak(arr2, n2, 0, n2-1);
    cout<<"Peak element index is "<<peak2<<", value is "<<arr2[peak2]<<endl;

    //equal elements
    int arr3[] = {10, 10, 10, 10, 10};
    int n3 = sizeof(arr3)/sizeof(int);
    int peak3 = RecursiveBinaryPeak(arr3, n3, 0, n3-1);
    cout<<"Peak element index is "<<peak3<<", value is "<<arr3[peak3]<<endl;
}
