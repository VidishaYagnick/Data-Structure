#include<iostream>
using namespace std;

class Queue
{
    public:
        int *arr;
        int size;
        int front;
        int rear;

        Queue(int size)
        {
            this->size = size;
            front = rear = -1;
            arr = new int[size];
        }

        void isEmpty()
        {
            if(front == -1 && rear == -1)
                cout << "Queue is Empty " << endl;
            
            else
                cout << "Queue is not empty " << endl;
        }

        void enqueue(int value)
        {
            if((front == 0 && rear == size-1) || (front == (rear + 1) % size))
            {
                cout << "Queue is full " << endl;
                return;
            }
            
            else if(front == -1) // Insert 1st element
            {
                front = rear = 0;
                arr[rear] = value;
            }

            else if (rear == size - 1 && front != 0) // property of circular queue
            {
                rear = 0;
                arr[rear] = value;
            }

            else
            {
                rear++;
                arr[rear] = value;
            }   

            cout << "Enqueued " << value << endl;    
        }

        void dequeue()
        {
            if(front == -1 && rear == -1)
            {
                cout << "Queue is empty " << endl;
                return;   
            }

            int num = arr[front];
            arr[front] = -1;
            
            if(front == rear)
                front = rear = -1;

            else if(front == size-1)
                front = 0;

            else
                front++;
            
            cout << "Dequeued " << num << endl;

        }
};

int main()
{
    Queue q(5);  // Create a queue of size 5

    q.isEmpty();  // Check if the queue is empty

    q.enqueue(10);  // Add elements to the queue
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.isEmpty();  // Check if the queue is empty after adding elements

    q.dequeue();  // Remove elements from the queue
    q.dequeue();

    q.enqueue(60);  // Test circular property
    q.enqueue(70);  // Should use the circular nature of the queue

    q.dequeue();  // Continue dequeuing to test further
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.isEmpty();  // Check if the queue is empty after removing all elements

    return 0;

}