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
            front = 0;
            rear = 0;
            arr = new int[size];

        }

        void enqueue(int value)
        {
            if(rear == size)
            {
                cout << "Queue is full " << endl;
                return;
            }

            arr[rear++] = value;
            cout << "Enqueued " << value << endl;
        }

        void dequeue()
        {
            if(rear == front)
            {
                cout << "Queue is empty " << endl;
                return;
            }

            int num = arr[front];
            arr[front] = -1;
            front++;

            if (front == rear)  //Reset queue when it becomes empty
            {
                front = 0;
                rear = 0;
            }
            cout << "Popped element is " << num << endl;
        }

        void isEmpty()
        {
            if(rear == front)
                cout << "Queue is empty " << endl;
            
            else
                cout << "Queue is not empty " << endl;
        }

        void Peek()
        {
            if(rear == front)
                cout << "Queue is empty " << endl;
            else
            {
                cout << "Front element is " << arr[front] << endl;
            }
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

    q.Peek();  // Peek at the front element of the queue

    q.dequeue();  // Remove elements from the queue
    q.dequeue();
    q.dequeue();

    q.Peek();  // Peek again to see the front element after some dequeues

    q.enqueue(60);  // Add another element to test enqueue after dequeue
    q.enqueue(70);

    q.dequeue();  // Remove all elements
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.isEmpty();  // Check if the queue is empty after removing all elements

    return 0;
}