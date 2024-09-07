#include<iostream>
using namespace std;

void Insertion_Sort(int arr[], int n)
{
    for(int i = 1; i <= n-1; i++)
    {
        int key = arr[i], j;
        for(j = i-1; j >= 0; j--)
        {
            if(arr[j] > key)
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int arr[] = {12, 54, 65, 7, 23, 9};
    int size = sizeof(arr)/sizeof(int);
    Insertion_Sort(arr, size);
    cout<<"Array after sorting :";
    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
}