#include<iostream>
using namespace std;

class Stack
{
    public:
        int data;
        Stack* next;

        Stack(int data) 
        {
            this->data = data;
            this->next = nullptr;
        }

        void isEmpty(Stack* head)
        {
            if(head == NULL)
                cout << "Stack is empty " << endl;
            else
                cout << "Stack is not empty " << endl;
        }

        void push(Stack* &head, int value)
        {
            Stack* newNode = new Stack(value);
                        
            newNode->data=value;
            newNode->next = head;
            head = newNode;
        }

        void pop(Stack* &head)
        {
            if(head == NULL)
                cout << "Stack is empty " << endl;

            Stack* temp = head;
            cout << "Popped element is " << head->data << endl;
            head = head->next;
            delete temp;
        }

        void peek(Stack* head)
        {
            if(head == NULL)
                cout << "Stack is empty " << endl;

            cout << "Peek element is " << head->data << endl;
        }
};

void print(Stack* head)
{
    // Start from the head of the linked list
    Stack* current = head;

    // Traverse the linked list until reaching the end (nullptr)
    while(current != NULL)
    {
        // Print the data of the current node
        cout << current->data << " ";

        // Move to the next node
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Stack* head = nullptr;
    Stack stack(0);  // Creating an object to access the member functions

    stack.isEmpty(head);  // Check if stack is empty

    stack.push(head, 10);  // Push elements onto the stack
    stack.push(head, 20);
    stack.push(head, 30);

    cout << "Stack after pushing 3 elements: ";
    print(head);

    stack.peek(head);  // Peek at the top element

    stack.pop(head);  // Pop an element
    cout << "Stack after popping 1 element: ";
    print(head);

    stack.isEmpty(head);  // Check if stack is empty

    return 0;

}