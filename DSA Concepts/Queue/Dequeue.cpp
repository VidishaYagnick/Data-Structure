#include<iostream>
using namespace std;

class Deque
{
    public:
        int front;
        int rear;
        int size;
        int* arr;

        Deque(int size)
        {
            this->size = size;
            front = -1;
            rear = -1;
            arr = new int[size];
        }

        void push_front(int value)
        {
            if((front == 0 && rear == size-1) || (front == (rear + 1) % size))
            {
                cout << "Queue is full " << endl; 
                return;
            }

            else if(front == -1) // inserting first element
                front = rear = 0;

            else if(front == 0) // cyclic nature
                front = size - 1;

            else
                front--;

            arr[front] = value;
            cout << "Enqueued " << value << endl;
        }

        void push_back(int value)
        {
            if((front == 0 && rear == size-1) || (front == (rear + 1) % size))
            {
                cout << "Queue is full " << endl;
                return;
            }

            else if(front == -1) // inserting first element
                front = rear = 0;

            else if(rear == size - 1)
                rear = 0;

            else
                rear++;
            
            arr[rear] = value;
            cout << "Enqueued " << value << endl;
        }

        void pop_front()
        {
            if(front == -1 && rear == -1)
            {
                cout << "Queue is empty " << endl;
                return;
            }

            int num = arr[front];

            if(rear == front)
                front = rear = -1;

            else if(front == size - 1)
                front = 0;
            
            else    
                front++;

            cout << "Dequeued " << num << endl;
        }

        void pop_back()
        {
            if(front == -1 && rear == -1)
            {
                cout << "Queue is empty " << endl;
                return;
            }

            int num = arr[rear];

            if(rear == front)
                front = rear = -1;

            else if(rear == 0)
                rear = size - 1;
            
            else    
                rear--;

            cout << "Dequeued " << num << endl;
        }

        void display(){
        int i = front;
        while(i!=rear){
            cout << arr[i] << " ";
            i = (i+1)%size;
        }
        cout << arr[rear] << endl;
    }
};

int main()
{
    Deque dq(5);  // Create a deque of size 5

    dq.push_back(10);   // Enqueue elements at the back
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);
    dq.display();

    dq.push_front(50);  // Enqueue element at the front
    dq.push_front(60);  // This should show "Queue is full"
    dq.display();

    dq.pop_back();   // Dequeue from the back
    dq.pop_back();
    dq.display();

    dq.pop_front();  // Dequeue from the front
    dq.pop_front();
    dq.display();

    dq.push_back(70);   // Enqueue element at the back
    dq.push_back(80);   // Should handle circular nature
    dq.display();

    dq.push_front(90);  // Enqueue element at the front, testing circular nature
    dq.display();

    dq.pop_front();  // Dequeue from the front
    dq.pop_back();   // Dequeue from the back

    dq.display();

    return 0;
}