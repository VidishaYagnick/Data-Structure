#include<iostream>
using namespace std;

//swap function
void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Selection_Sort(int arr[] ,int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j <= n-1; j++)
        {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
    swap(arr[i],arr[minIndex]);
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr)/sizeof(int);
    Selection_Sort(arr, size);
    cout<<"array after sorting : ";
    for(int i = 0; i<size; i++)
        cout<<arr[i]<<" ";

}