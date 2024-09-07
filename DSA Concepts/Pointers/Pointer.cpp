#include<iostream>
using namespace std;

int main()
{
    /*
    Why do we need pointer ?
    When we write cout<<num; a memory is not named as 'num'. num is stored at a memory location. Pointers are used to access that memory location.

    Symbol table : A Symbol table is a data structure used by the compiler, where each identifier in program’s source code is stored along with information associated with it relating to its declaration. It stores identifier as well as it’s associated attributes like scope, type, line-number of occurrence, etc.
    */ 

    int i = 5;
    
    // Declare a pointer with initialisation
    int *ptr = &i;
    // Ptr is a pointer to int and & is address of Operator

    cout<<"Address of i is "<< &i << endl;
    cout<<"Address of i is "<< ptr << endl;

    cout<<"Value in i is "<< i << endl;
    cout<<"Value in i is "<< *ptr << endl;
    // *ptr is dereference operator - used to access the value stored at the memory address pointed to by a pointer

    // data type of pointer is same as the value it going to point
    double num = 7;
    double *ptr2 = &num;

    //size of pointer and add/subtract to pointer
    cout<<"Size of int is "<< sizeof(i) << endl;
    cout<<"Size of pointer is "<< sizeof(ptr) << endl; //4
    cout<<"Size of double is "<< sizeof(num) << endl;
    cout<<"Size of pointer is "<< sizeof(ptr2) << endl; //4
    //size of pointer remains same as it stores address

    // add/ subtract
    // ptr = ptr + 1 --> 100 to 104
    // ptr = ptr - 1 --> 100 to 96

    // Modifying the values 

    (*ptr)++; // increments the value at address stored in ptr and it is equivalent to i + 1
    cout<<"Value in i after increment is "<< *ptr << endl;
    cout<<"Value in i after increment is "<< i << endl;

    // Copy the variable
    int a = i;
    cout<<"Value of a "<< a << endl;
    a++; // it will not change the value of i

    // Ways to initialise a pointer

    //1. int *ptr; -- BAD PRACTICE -- points to a garbage memory address

    int *ptr1 = 0; // 2. A null pointer

    ptr1 = &i; // **Imp** : Initialistaion after declaration

    // copying a pointer
    int *copy = ptr;
    cout<<" Value of ptr "<< ptr << " Value of copy "<< copy << endl;
    cout<<" Value at ptr "<< *ptr << " Value at copy "<< *copy << endl;



    return 0;
}