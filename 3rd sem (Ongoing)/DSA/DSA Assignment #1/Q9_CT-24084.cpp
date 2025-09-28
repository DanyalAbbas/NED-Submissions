#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

/*Write a function to reverse a doubly linked list. Your solution should correctly update the
next and prev pointers for each node.*/

// helper function to display the LL
void DisplayStuff(Node* head)
{
    while(head)
    {
        cout<<head->data<<"<->";
        head = head->next;
    }
    cout<<"nullptr"<<endl;
}


void reverse(Node*& head)
{
    Node* next = head;
    Node* prev = nullptr;
    Node* curr = head; // temp = 1->2->3->4
    while(curr) // loops until temp is not NULL
    {
        // in DLL, it is very easy to reverse the LL, we just swap the next and prev pointers of each node
        Node* temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // then we update our prev and curr pointers
        prev = curr;
        // make curr equal to its previous value which is now its next value
        curr = curr->prev;

    }
    head = prev; // now as we are doing everything by reference we dont need to return anything, just update head to prev
}

int main()
{
    vector<int> list {1,3,6,7,8,9,0,6};
    Node* head = new Node(list[0]);
    Node* temp = head;

    int count = 1;
    while (count < list.size())
    {
        temp->next = new Node(list[count]);
        temp->next->prev = temp;
        temp = temp->next;
        count++;
    }

    DisplayStuff(head);
    reverse(head);
    DisplayStuff(head);

}