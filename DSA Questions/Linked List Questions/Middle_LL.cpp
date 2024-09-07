/*
Find Middle of the Linked List
Given a Singly Linked List, the task is to find the middle of the linked list. If the number of nodes are even, then there would be two middle nodes, so return the second middle node.

Find Middle of the Linked List using Floyd’s Cycle Finding Algorithm:
We can use the Floyd’s Cycle Finding Algorithm, also known as Hare and Tortoise Algorithm to find the middle of the linked list. Traverse linked list using a slow pointer and a fast pointer. Move the slow pointer to the next node(one node forward) and the fast pointer to the next of the next node(two nodes forward). When the fast pointer reaches the last node or NULL, then the slow pointer will reach the middle of the linked list.

In case of odd number of nodes in the linked list, slow_ptr will reach the middle node when fast_ptr will reach the last node and in case of even number of nodes in the linked list, slow_ptr will reach the middle node when fast_ptr will become NULL.
*/

#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next = nullptr;

        Node(int value)
        {
            this->data = value;
            this->next = nullptr;
        }
};

int FindMiddle(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head->data;
    
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

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
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    // head->next->next->next->next->next->next = new Node(70);

    cout << "Linked List is " << endl;
    print(head);

    int middle = FindMiddle(head);
    cout << "Middle element is " << middle << endl;

    return 0;
}