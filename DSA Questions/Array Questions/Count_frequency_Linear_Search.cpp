/*
Count number of occurrences (or frequency) in a sorted array :  
Given a sorted array arr[] of size N and a number X, you need to find the number of occurrences of X in given array.
*/

#include<iostream>
using namespace std;

int getFrequency(int arr[], int n, int x)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n, x;
    cout<<"Enter the size of array ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element to find its occurence ";
    cin>>x;

    cout<<"Occurence of element is "<<getFrequency(arr, n, x);

    return 0;  
}