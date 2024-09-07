// Reverse a Linked List using Iterative Method (Best Approach)

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

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void ReverseList(Node* &head)
{
    if(head == NULL || head->next == NULL)
        return;

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = nullptr;

    while(curr != NULL)
    {
        forward = curr->next; // so that other part of LL is not lost
        
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
     head = prev;
}

int main()
{
    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Given Linked list " << endl;
    print(head);

    ReverseList(head);
    cout << "Reversed Linked List " << endl;
    print(head);
}

// Time Complexity: O(N), Traversing over the linked list of size N. 
// Auxiliary Space: O(1)