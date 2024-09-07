#include<iostream>
using namespace std;

class Node
{
    public: 
        int data;
        Node* next;

        Node(int value)
        {
            this->data = value;
            this->next = NULL;
        }
};

void print(Node* last)
{
    // list is empty
    if(last == NULL)
        return;

    Node* head = last->next;

    do
    {
        cout << head->data << " ";
        head = head->next;
    }while(head != last->next); // NOTE

    cout << endl;
}

void insertAtBeginning(Node* &last, int value)
{   
    // list is empty
    if(last == NULL)
    {
        Node* newNode = new Node(value);

        newNode->data = value;
        newNode->next = newNode;
        last = newNode;
    }   
    else
    {
        Node* newNode = new Node(value);

        newNode->data = value;
        newNode->next = last->next;
        last->next = newNode;
    }
}

void insertAtLast(Node* &last, int value)
{
    Node* newNode = new Node(value);

    newNode->data = value;
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
}

void insertAtPos(Node* &last, int pos, int value)
{
    int count = 1;

    if(pos == 1)
    {
        Node* newNode = new Node(value);

        newNode->data = value;
        newNode->next = last->next;
        last->next = newNode;
    }
    else
    {
        Node* head = last->next;
        while(count < pos - 1)
        {
            head = head->next;
            count++;
        }

        Node* newNode = new Node(value);

        newNode->data = value;
        newNode->next = head->next;
        head->next = newNode;

        if(head == last)
        {
            last = newNode;
        }
    }
}

void deleteFromStart(Node* &last)
{
    if(last == NULL)
        cout << "List is empty " << endl;

    Node* head = last->next;

    if(head == last)
    {
        delete head;
        last = NULL;
    }
    else
    {
        last->next = head->next;
        delete head;
    }     
}

void deleteFromEnd(Node* &last)
{
    if(last == NULL)
        return;

    Node* head = last->next;

    if(last == last->next)
    {
        delete head;
        last = NULL;
    }
    else
    {
        while(head->next != last)
        {
            head = head->next;
        }

        head->next = last->next;
        delete last;

        last = head;
    }
}

void deleteAtPos(Node* &last, int pos)
{
    if(pos == 1)
    {
        deleteFromStart(last);
        return;
    }

    int count = 1;
    Node* curr = last->next;
    Node* prev = NULL;

    while(count < pos)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    prev->next = curr->next;
    
    if(curr == last)
        last = prev;

    delete curr;
}

int main()
{
    Node* last = nullptr;

    insertAtBeginning(last, 10);
    cout << "LL after insertion in empty list " << endl;
    print(last);

    insertAtBeginning(last, 22);
    cout << "LL after insertion at beginning " << endl;
    print(last);

    insertAtBeginning(last, 23);
    cout << "LL after insertion at beginning " << endl;
    print(last);

    insertAtLast(last, 15);
    cout << "LL after insertion at end " << endl;
    print(last);

    insertAtPos(last, 3, 30);
    cout << "LL after insertion at given position " << endl;
    print(last);

    deleteFromStart(last);
    cout << "LL after deletion of 1st node " << endl;
    print(last);

    deleteFromEnd(last);
    cout << "LL after deletion of last node " << endl;
    print(last);

    deleteAtPos(last, 2);
    cout << "LL after deletion at a given position " << endl;
    print(last);

    return 0;
}