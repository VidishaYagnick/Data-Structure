#include <iostream>
using namespace std;

int main()
{
    int i = 5;
    int* ptr  = &i;
    int** ptr2 = &ptr;

    cout << "Value of i is " << i << endl;
    cout << "Value of i using ptr is " << *ptr << endl;
    cout << "Value of i using ptr2 is " << **ptr2 << endl;

    cout << "Address of i is " << &i << endl;
    cout << "Address of i using ptr is " << ptr << endl;
    cout << "Address of i using ptr2 is " << *ptr2 << endl;

    cout << "Value of ptr using i is " << &i << endl;
    cout << "Value of ptr is " << ptr << endl;
    cout << "Value of ptr using ptr2 is " << *ptr2 << endl;

    cout << "Value of ptr2 using ptr is " << &ptr << endl;
    cout << "Value of ptr2 is " << ptr2 << endl;

    // Double pointers and functions:
    // If we implement following inside a function, will things change in main function ?
    // p = p + 1 ---- NO
    // *p = *p + 1 --- YES
    // **p = **p + 1 --- YES

    return 0;
}