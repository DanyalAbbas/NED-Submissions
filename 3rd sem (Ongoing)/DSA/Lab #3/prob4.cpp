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

    void BubbleSort() {
        if (!head) return;
        bool swapped;
        do {
            swapped = false;
            Node* current = head;
            while (current->next) {
                if (current->data < current->next->data) {
                    swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }


};


int main() {
    DoublyLinkedList l;
    l.append(5);
    l.append(3);
    l.append(8);
    l.append(1);
    l.append(4);
    cout << "Original List: ";
    l.display();
    l.BubbleSort();
    cout << "Sorted List: ";
    l.display();
    
}
