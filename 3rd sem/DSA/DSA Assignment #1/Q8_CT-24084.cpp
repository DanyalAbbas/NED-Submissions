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

/*Implement a function to delete a node from a doubly linked list, given a pointer to the
node to be deleted.*/

// Another helper function to display the LL
void DisplayStuff(Node* head)
{
    while(head)
    {
        cout<<head->data<<"<->";
        head = head->next;
    }
    cout<<"nullptr"<<endl;
}

// This time we will Delete a node by its index
void deleteNodebyIndex(Node*& head, int idx)
{
    // if head is null or idx is negative we just return
    if(!head || idx < 0) return;

    Node* temp = head;
    // if idx is 0, we have to delete the head node
    if(!idx)
    {
        // if head's next is null, which means there is only one node in the LL
        if(!head->next)
        {
            // we delete head and make it null
            delete head;
            head = nullptr;
            return;
        }
        else
        {
            // else we update head to its next value
            head = head->next;
            // then we make the prev of new head null
            head->prev = nullptr;
            // then we delete the old head which is stored in temp
            delete temp;
            return;
        }
    }

    // else we traverse the LL till we reach the idx or end of LL
    int count = 0;
    while(temp && count < idx)
    {
        temp = temp->next;
        count++;
    }

    // if temp is null, which means idx was out of bounds
    if(!temp) return;

    // else we update the next of prev node to next of current node
    if(temp->prev) temp->prev->next = temp->next;
    // and if next node exist, we update its prev to prev of current node
    if(temp->next) temp->next->prev = temp->prev;

    // finally we delete the current node
    delete temp;
    
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
    
    cout<<"Current LinkedList: ";DisplayStuff(head);
    deleteNodebyIndex(head, 0);
    cout<<"After Deleting index 0: ";DisplayStuff(head);
    deleteNodebyIndex(head, 3);
    cout<<"After Deleting index 3: ";DisplayStuff(head);
    deleteNodebyIndex(head, 10);
    cout<<"After Deleting index 10: ";DisplayStuff(head);
    deleteNodebyIndex(head, 4);
    cout<<"After Deleting index 4: ";DisplayStuff(head);
    deleteNodebyIndex(head, -1);
    cout<<"After Deleting index -1: ";DisplayStuff(head);

    return 0;
}