#include<bits/stdc++.h>
#include<exception>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

/*Write a function to insert a new node at a specific position (e.g., at the beginning, at the
end, or after a given node) in a circular singly linked list.*/


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


// we will be inserting at end, begin and middle by value
// I am using default parameters for our case
void InsertbyVal(Node*& head, int val, int after=NULL, bool atStart=false)
{
    // Make a new Node with new given value
    Node* NewVal = new Node(val);
    
    // check if head is not null
    if(head)
    {
        // check if after variable is not null
        if(after)
        {
            // if its not then we traverse the LL and add the value after it
            Node* temp = head;
            while(temp->next != head)
            {
                if(temp->data == after) break;
                temp = temp->next;
            }
            // if we dont find the value, we throw an exception
            if (temp->data != after) throw invalid_argument("value not found.");
            else
            {
                NewVal->next = temp->next;
                temp->next = NewVal;
            }
        }
        else
        {
            // else we traverse the whole LL and stop at the point of circulation
            Node* temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }

            // if atStart variable is true
            if (atStart)
            {
                // we update the temp's next Value to NewVal 
                temp->next = NewVal;
                // and newVal's next to head
                NewVal->next = head;
                // then finally assign head the New Val value
                head = NewVal;
            }
            // if atStart variable is false
            else
            {
                // we do all the things we did above but not assigning head to NewVal
                temp->next = NewVal;
                NewVal->next = head;
            }
        }

    }
    // If head is null
    else
    {
        // then we assign head NewVal and make it point to itself
        head = NewVal;
        head->next = head;
    }

}


int main()
{
    vector<int> list {1,3,6,7,8,9,0,6};
    Node* head = MakeALinkedList(list);

    cout<<"Current LinkedList: ";DisplayStuff(head);
    InsertbyVal(head, 2, NULL, true);
    cout<<"Afer Inserting at Start: ";DisplayStuff(head);
    InsertbyVal(head, 69, 7);
    cout<<"Afer the Value 7: ";DisplayStuff(head);
    InsertbyVal(head, 72, NULL);
    cout<<"Afer Inserting at end: ";DisplayStuff(head);

}