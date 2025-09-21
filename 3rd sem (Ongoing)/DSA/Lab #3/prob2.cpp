#include <iostream>
using namespace std;

// 2. Implement class of a double ended queue using doubly Linked List.

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Deque {
private:
    Node* front;
    Node* rear;
    int size;
    int capacity;
public:
    Deque(int cap) : front(nullptr), rear(nullptr), size(0), capacity(cap) {}

    void insertFront(int val) {
        if (size == capacity) {
            cout << "Deque is full" << endl;
            return;
        }
        Node* newNode = new Node(val);
        if (!front) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    void insertRear(int val) {
        if (size == capacity) {
            cout << "Deque is full" << endl;
            return;
        }
        Node* newNode = new Node(val);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        size++;
    }

    void deleteFront() {
        if (!front) {
            cout << "Deque is empty" << endl;
            return;
        }
        Node* temp = front;
        if (front == rear) { // Only one element
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
        size--;
    }

    void deleteRear() {
        if (!rear) {
            cout << "Deque is empty" << endl;
            return;
        }
        Node* temp = rear;
        if (front == rear) { // Only one element
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
        size--;
    }

    void display() {
        if (!front) {
            cout << "Deque is empty" << endl;
            return;
        }
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq(5);
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.display(); // Output: 5 10 20
    dq.deleteFront();
    dq.display(); // Output: 10 20
    dq.deleteRear();
    dq.display(); // Output: 10
    return 0;
}