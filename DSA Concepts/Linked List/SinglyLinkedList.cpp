/*
Operations on Singly Linked List :
1. Traversal
2. Searching
3. Length
4. Insertion:
    a. Insert at the beginning
    b. Insert at the end
    c. Insert at a specific position
5. Deletion:
    a. Delete from the beginning
    b. Delete from the end
    c. Delete a specific node
*/
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        // Constructor to initialize the node with data
        Node(int data)
        {
            this -> data = data;
            this -> next = NULL; 
        }

        // Destructor to delete nodes (code later)
        /*~Node()
        {
            int value = this->data;

        }
        */
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

bool Search(Node* head, int target)
{
    while(head != NULL)
    {
        if(head->data == target)
            return true;

        head = head->next;
    }
    return false;
}

int findLength(Node* head)
{
    int len = 0;

    Node* current = head;

    while(current != NULL)
    {
        len++;
        current = current->next;
    }
    return len;
}

// Node* insertAtBeginning(Node* head, int value) avoid using this, pass the address instead
void insertAtBeginning(Node* &head, int value)
{
    Node* newNode = new Node(value);
    newNode -> next = head;
    head = newNode;

}

void insertAtEnd(Node* &head, int value) // use this method instead
{
    Node* newNode = new Node(value);

    Node* temp = head;

    // find the last node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    // add the node at end
    temp->next = newNode;
}

void insertAtPosition(Node* &head, int pos, int data)
{
    if(pos == 1)
    {
        insertAtBeginning(head, data);
        return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;
    int count = 1;
    
    // for n position, move n-1 steps
    while(count < pos-1)
    {
        temp = temp->next;
        count++;
    }  
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirstNode(Node* &head)
{
    if(head == NULL)
        return;
    
    Node* temp = head;
    head = temp->next;

    // temp->next = NULL; // use if calling destructor

    delete temp; // free memory
}

void deleteLastNode(Node* &head)
{
    if(head == NULL)
        return;
    
    if(head->next == NULL)
    {
        delete head;
        return;
    }

    // Find the second last node
    Node* second_last = head;
    while(second_last->next->next != NULL)
    {
        second_last = second_last->next;
    }

    // Delete last node
    delete (second_last->next);
 
    // Change next of second last
    second_last->next = NULL;
}

void deleteAtPosition(Node* &head, int pos)
{
    if(pos == 1)
    {
        Node* temp = head;
        head = head->next;

        delete temp;
    }
    else
    {
        Node* prev = NULL;
        Node* curr = head;

        int count = 1;

        while(count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;

        // free the space
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    // create a new node
    Node* node1 = new Node(10);

    // head pointing to node1
    Node* head = node1;

    cout << "LL before insertion " << endl;
    print(head);

    cout << Search(head, 10) << endl;
    cout << Search(head, 8) << endl;
    cout << findLength(head) << endl;

    // head = insertAtBeginning(head, 12);  avoid using this
    insertAtBeginning(head, 12);
    cout << "LL after insertion at head " << endl;
    print(head);

    insertAtEnd(head, 15); 
    cout << "LL after insertion at end " << endl;
    print(head);

    insertAtPosition(head, 3, 20);
    cout << "LL after insertion at given position " <<  endl;
    print(head);

    deleteFirstNode(head);
    cout << "LL after deletion of head " << endl;
    print(head);

    deleteLastNode(head);
    cout << "LL after deletion of last node " << endl;
    print(head);

    deleteAtPosition(head, 2);
    cout << "LL after deletion at a given position " << endl;
    print(head);

    return 0;
}