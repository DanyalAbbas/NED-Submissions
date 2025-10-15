#include <bits/stdc++.h>
using namespace std;

/*Implement a queue using a list or an array. Include the basic operations: enqueue (add an
element), dequeue (remove an element), peek (view the front element), and is_empty.*/


class Queue
{
    int front, rear, capacity;
    int *queue;
    public:
    Queue(int c)
    {
        front = rear = 0;
        capacity = c;
        queue = new int[c];
    }

    void enqueue(int data)
    {
        if (capacity == rear)
        {
            cout << "Queue is full\n";
            return;
        }
        else
        {
            queue[rear] = data;
            rear++;
        }
        return;
    }
    void dequeue()
    {
        if (front == rear)
        {
            cout << "Queue is empty\n";
            return;
        }
        else
        {
            for (int i = 0; i < rear - 1; i++)
            {
                queue[i] = queue[i + 1];
            }
            rear--;
        }
        return;
    }
    int peek()
    {
        if (front == rear)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return queue[front];
    }
    bool is_empty()
    {
        return front == rear;
    }

    ~Queue() { delete[] queue; }

};


int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    if (q.is_empty())
        cout << "Queue khali \n";
    else
        cout << "Queue no khali\n";

    return 0;
}