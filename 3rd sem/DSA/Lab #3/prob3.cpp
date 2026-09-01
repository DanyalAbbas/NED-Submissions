#include <iostream>
using namespace std;

// Create two doubly link lists, say L and M. List L should be containing all even elements from 2 to 10 and list M should contain all odd elements from 1 to 9. Create a new list N by concatenating list L and M.

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void concatenate(DoublyLinkedList& other) {
        if (!other.head) return;
        if (!head) {
            head = other.head;
            tail = other.tail;
        } else {
            tail->next = other.head;
            other.head->prev = tail;
            tail = other.tail;
        }
        other.head = other.tail = nullptr; 
    }

};


int main() {
    DoublyLinkedList L, M, N;
    for (int i = 2; i <= 10; i += 2) L.append(i);
    for (int i = 1; i < 10; i += 2)  M.append(i);
    cout << "List L (Even): ";
    L.display();
    cout << "List M (Odd): ";
    M.display();
    N.concatenate(L);
    N.concatenate(M);
    cout << "Concatenated List N: ";
    N.display();
    return 0;
}