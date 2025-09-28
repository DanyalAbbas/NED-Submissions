#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

/*Given a circular singly linked list, rotate it by k positions. For example, with n=7 and k=3,
the list 1, 2, 3, 4, 5, 6, 7 becomes 5, 6, 7, 1, 2, 3, 4.*/

// I will be using the same helper function for creating the linkedlist as last question
Node* MakeALinkedList(vector<int> values)
{
    Node* head = new Node(values[0]);
    Node* temp = head;

    int count = 1;
    while (count < values.size())
    {
        temp->next = new Node(values[count]);
        temp = temp->next;
        count++;
    }
    temp->next = head;
    
    return head;
}

// Another helper function to display the LL
void DisplayStuff(Node* head)
{
    Node* temp = head;
    do {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << "head" << endl;
}

void RotateKPosition(Node*& head, int k)
{
    // if head is null or k is 0 we just return
    if(!head || k == 0) return;

    Node* temp = head;
    int n = 1;
    // we traverse the LL until we reach the end to find its size
    while(temp->next != head)
    {
        temp = temp->next;
        n++;
    }

    // then we just subtract n by k and transfer the head to that position
    for(int i = 0; i < n-k; i++)
        head = head->next;

}

int main()
{
    vector<int> list {1,2,3,4,5,6,7};
    Node* head = MakeALinkedList(list);

    cout<<"Current LinkedList: ";DisplayStuff(head);
    RotateKPosition(head, 3);
    cout<<"After Rotating by 3 positions: ";DisplayStuff(head);

    return 0;
}