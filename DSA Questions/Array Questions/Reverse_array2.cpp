/*
2. Array Reverse Using a Loop (In-place):
a. Iterate through the array using two pointers (start and end).
b. Swap elements at the start and end pointers.
c. Move the start pointer towards the end and the end pointer towards the start until they meet or cross each other.
*/

#include<iostream>
using namespace std;

void ReverseWithTwoPointer(int arr[],  int start, int end)
{
    int temp;
    while(start <= end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
}

void PrintArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = { 10, 20, 30, 40, 50 };
    int n = sizeof(arr) / sizeof(int);

    cout<<"Original Array :";
    PrintArray(arr,n);
    
    ReverseWithTwoPointer(arr,0,n-1);

    cout<<"Reversed Array :";
    PrintArray(arr,n);

}

// Time complexity : O(n)
// Space complexity : O(1)
