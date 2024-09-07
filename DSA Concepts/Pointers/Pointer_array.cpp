#include<iostream>
using namespace std;

int main()
{
    int arr[10] = {0, 1, 2, 3, 4,}; // name of array stores the address of 1st element
    
    cout << "Address of 1st element of array is " << arr << endl;
    cout << "Address of 1st element of array is " << &arr << endl;
    cout << "Address of 1st element of array is " << &arr[0] << endl;

    // Dereferencing operator in array
    cout << "Using dereferencing operator in array " << *arr << endl;
    cout << "Using dereferencing operator in array " << ++(*arr) << endl;

    // Printing all elements using dereference operator

    cout << "1st element : " << *arr << endl;
    cout << "2nd element : " << *(arr + 1) << endl;
    cout << "3rd element : " << *(arr + 2) << endl;
    cout << "4th element : " << *(arr + 3) << endl;
    cout << "5th element : " << *(arr + 4) << endl;

    // Interpreting arr[i] which is *(arr + i)
    // Hence i[arr] will not give error as it is same as *(i + arr)

    int i = 2;
    cout << "i[arr] is " << i[arr] << endl;

    // Difference between pointer and array :
    // 1. sizeof(arr) = 4 * size of array) is not equal to size of(ptr) = 4
    // 2. &arr is not equal to &ptr
    // 3. Symbol table content cannot be changed.

    // 1st difference
    int *ptr = &arr[0];

    cout << "Size of arr " << sizeof(arr) << endl;
    cout << "Size of ptr " << sizeof(ptr) << endl;

    // 2nd difference
    cout << "Dereferencing arr " << &arr << endl;
    cout << "Dereferencing  ptr " << &ptr << endl;

    // 3rd difference
    // arr = arr + 1 -- This will throw error
    // ptr = ptr + 1 -- This will not throw error

    // **CHARACTER ARRAY**

    char ch[6] = "abcde";
    cout << ch << endl;  // this will not print address
    cout << &ch << endl; // this will print address

    char *c =  &ch[0]; // &ch will not work, this is a syntax for creating string
    cout << c << endl; // this will also not print address
    
    // Implementation of cout for int and char is different
    // char ch[6] = "abcde" ---- 1. Make a temp memory and store abcde and a null char 2. Copy this string to ch
    // char *ch = "abcde" (NEVER USE THIS)---- 1. Make a temp memory and store abcde 2. Make a pointer ch pointing to 1st char in array 

    // **NOTE** : arr[] is a pointer passed to a function
    // Benefit of passing address of array - we can pass a part of array

    // Pointers and function:
    // If we implement p = p + 1 (this will not change anything in main function) and *p = *p + 1 (this will change value in main function)

    return 0;
}