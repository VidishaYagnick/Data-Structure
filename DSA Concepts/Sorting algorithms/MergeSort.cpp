#include <iostream>
using namespace std;

void Merge(int arr[], int low, int mid, int high)
{
    int i,j,k;
    int B[30];
    i = low, j = mid + 1, k = low;
    while(i <= mid && j <= high) 
    {
        if(arr[i] < arr[j])
        {
            B[k] = arr[i];
            i++; k++;
        }
        else
        {
            B[k] = arr[j];
            j++; k++;
        }
    }
    while(i <= mid)
    {
        B[k] = arr[i];
        i++;
        k++;
    }
    while(j <= high)
    {
        B[k] = arr[j];
        j++;
        k++;
    }

    for(int i = 0; i <= high; i++)
    {
        arr[i] = B[i];
    }
}

void Merge_Sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        Merge_Sort(arr, low, mid);
        Merge_Sort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}
int main()
{
    int arr[] = {9, 14, 4, 4, 8, 7, 5, 6};
    int size = sizeof(arr) / sizeof(int);
    int low = 0;         // first index
    int high = size - 1; // last index
    Merge_Sort(arr, low, high);
    cout << "Array after sorting : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}