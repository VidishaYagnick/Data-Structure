#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;

}

void Bubble_Sort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        bool is_Swapped = false;    //optimization to make best case complexity : O(n)
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j + 1])
            {
                swap(arr[j],arr[j + 1]);
                is_Swapped = true;
            }
        }
        if (is_Swapped == false)
            break;
    }
}

int main()
{
    int arr[] = {10, 1, 7, 6, 14, 9};
    int size = sizeof(arr)/sizeof(int);
    Bubble_Sort(arr, size);
    cout<<"Array after Sorting : ";
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}