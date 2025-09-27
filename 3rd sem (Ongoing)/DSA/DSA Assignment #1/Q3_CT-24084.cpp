#include<bits/stdc++.h>
using namespace std;

/*Write a program to find the middle node of a singly linked list.*/

class Node
{
    public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// helper function to make a valid linkedlist
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


// we will be using the slow fast pointer method
// essentially its just that the fast pointer runs twice as fast compared to the slow one
// so it will reach end when the slow pointer is in the middle, hence we return the slow pointer  
Node* middleterm(Node* head)
{
    Node *slow = head;
    Node *fast = head;

    // we are checking that if fast and its next two nodes even exist
    while (fast && fast->next && fast->next->next)
    {
        // fast pointer is twice as faster than the slow pointer
        fast = fast->next->next;
        slow = slow->next;
    }

    // the loop ended which means that fast pointer has reached the end so we return slow pointer
    return slow;
} 


int main()
{
    vector<int> list = {1,3,5,6,7,8,8};
    // make a linkedlist using our helper function
    Node *head = MakeALinkedList(list);

    // send in the head value to our middlterm function
    Node *val = middleterm(head);

    // check the middle value
    cout<<"The middle value is : "<<val->data<<endl;
    
}