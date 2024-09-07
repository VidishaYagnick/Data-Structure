#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *arr;

    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    void isEmpty()
    {
        if (top == -1)
            cout << "Stack is Empty " << endl;

        else
            cout << "Stack is not Empty " << endl;
    }

    void isFull()
    {
        if (top == size)
            cout << "Stack is Full " << endl;

        else
            cout << "Stack is not Full " << endl;
    }

    void push(int data)
    {
        if(top >= size)
            cout << "Stack Overflow" << endl;

        else
        {
            arr[++top] = data; 
            cout << "Pushed " << data << endl;
        }
    }

    void pop()
    {
        if(top == -1)
            cout << "Stack is empty" << endl;

        else
        {
            cout << "Popped element is " << arr[top] << endl;
            top--;
        }
    }

    void peek()
    {   
        if(top == -1)
        {
            cout << "Stack is empty " << endl;
        }
        else
        {
            cout << "Peek element is " << arr[top] << endl;
        }
    }
};

int main()
{
    Stack stack(7);

    stack.isEmpty();

    stack.push(2);
    stack.push(5);
    stack.push(7);
    stack.push(9);

    stack.peek();

    stack.pop();

    stack.isFull();

    return 0;
}