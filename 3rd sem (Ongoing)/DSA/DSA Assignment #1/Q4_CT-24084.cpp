#include<bits/stdc++.h>
using namespace std;

/*Implement a function to reverse a singly linked list. Your solution should update the
pointers of the nodes and not just print the elements in reverse.*/

class Node
{
    public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

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

Node* reverse(Node* head)
{
    /* if we want to reverse LL, we need to keep track of what   
    is behind us and whats ahead, because doing so prevents us from getting stuck in a loop*/
    Node* next = head;
    Node* prev = nullptr;

    // we create a temp node variable to traverse
    Node* temp = head; // temp = 1->2->3->4
    while(temp) // loops until temp is not NULL
    {
        // we save the next data of LL in a pointer 
        next = temp->next;
        // we break the LL chain by making temp->next to prev which is null rn
        temp->next = prev;
        // then we assign the temp to prev, so in 1st iteration prev looks like this: 1->null
        prev = temp;
        // then we connect the LL chain by using our next variable by assigning it to temp
        temp = next;
        // so now temp looks like this: 2->3->4
        
    }

    // we return the reversed linkedlist
    return prev;
}

int main()
{
    vector<int> list = {1,2,3,4};
    Node* head = MakeALinkedList(list);
    DisplayStuff(head);
    head = reverse(head);
    DisplayStuff(head);

}