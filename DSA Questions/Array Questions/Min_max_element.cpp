#include<iostream>
using namespace std;

int getMin(int arr[], int n)
{
    int min = arr[0];
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < min)
            min = arr[i];
    }
    return min;
}

int getMax(int arr[], int n)
{
    int max = arr[0];
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main()
{
    int arr[] = { 12, 1234, 45, 67, 1 };
    int n = sizeof(arr) / sizeof(int);
    cout<<"Minimum element of given array is "<<getMin(arr,n)<<endl;
    cout<<"Maximum element of given array is "<<getMax(arr,n)<<endl;
}

// Time complexity : O(n)
// Space complexity : O(1)