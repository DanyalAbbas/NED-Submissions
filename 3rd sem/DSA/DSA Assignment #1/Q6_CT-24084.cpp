#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

/*Given the head of a linked list, remove the n nodes from the list and return its head.*/

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
    
    return head;
}

// Another helper function to display the LL
void DisplayStuff(Node* head)
{
    while(head)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"nullptr"<<endl;
}

Node* removeNnodes(Node* head, int n)
{
    // first we check if head even exist and n is not equal to 0
    while(head && n)
    {
        // we save the current head value in a temp pointer
        Node* temp = head;
        // update the head value to its next
        head = head->next;
        // then delete the temp freeing the taken address
        delete temp;
        // and then decrementing value of n
        n--;
    }
    // return head after loop is completed
    return head;
}

int main()
{
    vector<int> list = {1,2,3,4,5,6};
    Node* head = MakeALinkedList(list);
    cout<<"Before removing N nodes : ";DisplayStuff(head);
    cout<<"After removing N nodes : ";DisplayStuff(removeNnodes(head, 5));

}

