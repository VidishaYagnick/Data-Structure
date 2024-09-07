/*
3. Array Reverse Inbuilt Methods (In-place):
--> Use inbuilt methods like reverse in Python or Array.Reverse in C#.
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int originalArray[] = { 1, 2, 3, 4, 5 };
    int size
        = sizeof(originalArray) / sizeof(int);

    // Using inbuilt method in C++
    reverse(originalArray, originalArray + size);

    // Print the reversed array
    for (int i = 0; i < size; i++) 
    {
        cout << originalArray[i] << " ";
    }

    return 0;
}

// Time complexity : O(n)
// Space complexity : O(1)
