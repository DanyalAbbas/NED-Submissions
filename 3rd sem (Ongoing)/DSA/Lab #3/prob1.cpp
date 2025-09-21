#include<iostream>
using namespace std;

// 1. Implement class of a Circular Queue using a circular Linked List.

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularQueue {
private:
    Node* front;
    Node* rear;
    int size;
    int capacity;
public:
    CircularQueue(int cap) : front(nullptr), rear(nullptr), size(0), capacity(cap) {}

    void enqueue(int val) {
        if (size == capacity) {
            cout << "Queue is full" << endl;
            return;
        }
        Node* newNode = new Node(val);
        if (!front) {
            front = rear = newNode;
            rear->next = front; // Point to itself
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Maintain circular link
        }
        size++;
    }

    void dequeue() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (front == rear) { // Only one element
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front; // Maintain circular link
            delete temp;
        }
        size--;
    }
    void display() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};


int main()
{
    CircularQueue cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display(); // Output: 10 20 30
    cq.dequeue();
    cq.display(); // Output: 20 30
    return 0;
}