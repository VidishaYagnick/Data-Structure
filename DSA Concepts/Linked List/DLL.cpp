#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* prev;
        Node* next;

    Node(int value)
    {
        this->data = value;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* head)
{
    // Start from the head of the linked list
    Node* current = head;

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

void insertAtHead(Node* &head, int value)
{
    Node* newNode = new Node(value);

    newNode->data = value;
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node* &head, int value)
{
    Node* curr = head;

    while(curr->next != NULL)
    {
        curr = curr->next;
    }

    Node* newNode = new Node(value);

    newNode->data = value;
    
    newNode->prev = curr;
    curr->next = newNode;
}

void insertAtPosition(Node* &head, int pos, int value)
{
    int count = 1;
    if(pos == 1)
    {
        Node* newNode = new Node(value);

        newNode->data = value;

        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    else
    {
        
        Node* temp = head;
        while(count < pos - 1)
        {
            temp = temp->next;   
        }
        Node* newNode = new Node(value);

        newNode->data = value;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;

    }
}

void deleteHead(Node* &head)
{
    Node* temp = head;
    head->next->prev = NULL;
    head = head->next;

    delete temp;
}

void deleteEnd(Node* &head)
{
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
}

void deleteAtPos(Node* &head, int pos)
{
    int count = 1;
    if(pos == 1)
    {
        Node* temp = head;
        head->next->prev = NULL;
        head = head->next;

        delete temp;
    }
    else
    {
        Node* temp = head;
        while(count < pos)
        {
            temp = temp->next;
            count++;
        }

        temp->prev->next = temp->next;

        if(temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
    }
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;

    cout << "LL before insertion " << endl;
    print(head);

    insertAtHead(head, 12);
    cout << "LL after insertion at head " << endl;
    print(head);

    insertAtHead(head, 22);
    cout << "LL after insertion at head " << endl;
    print(head);

    insertAtEnd(head, 15);
    cout << "LL after insertion at end " << endl;
    print(head);

    insertAtPosition(head, 2, 20);
    cout << "LL after insertion at given position " << endl;
    print(head);

    deleteHead(head);
    cout << "LL after deletion of head " << endl;
    print(head);

    deleteEnd(head);
    cout << "LL after deletion of last node " << endl;
    print(head);

    deleteAtPos(head, 2);
    cout << "LL after deletion at given position " << endl;
    print(head);

    deleteAtPos(head, 2);
    cout << "LL after deletion at given position " << endl;
    print(head);

    return 0;
}