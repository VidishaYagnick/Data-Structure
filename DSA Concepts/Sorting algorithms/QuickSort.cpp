#include<iostream>
using namespace std;

int Partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while(arr[i] <= pivot)
        {
            i++;
        }
        while(arr[j] > pivot)
        {
            j--;
        }
        if(i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i < j);

    //swap arr[low] and arr[j]
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    
    return j;
}

void Quick_Sort(int arr[], int low, int high)
{
    int partitionIndex;
    if(low < high) // so that array is not empty
    {
        partitionIndex = Partition(arr, low, high); 
        Quick_Sort(arr, low, partitionIndex - 1);
        Quick_Sort(arr, partitionIndex + 1, high);
    }
}

int main()
{
    int arr[] = {3, 5, 2, 13, 12, 1, 7};
    int size = sizeof(arr)/sizeof(int);
    Quick_Sort(arr, 0, size-1);
    cout<<"Array after sorting : ";
    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
}
