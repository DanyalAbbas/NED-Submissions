#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

/*Given the heads of two sorted singly linked lists, merge the two lists into a single sorted list.
The new list should be made by splicing together the nodes of the first two lists.*/

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

// we have done this in lab
Node* MergeTwoSortedLL(Node* l1, Node* l2)
{
    // if the l1 pointer is nul we just return l2
    if(!l1) return l2;
    // same way if l2 pointer is null we return l1
    if(!l2) return l1;

    // if both contain some values then we compare those values together
    if(l1->data < l2->data){
        /* now if l1's data was smaller than l2's, we recursively call the same function
        with l1's value as its next value*/
        l1->next = MergeTwoSortedLL(l1->next, l2);
        // the function has ended, which means the function returned null looking at our base conditions
        return l1; // so then we return l1 since it was the first value (head) of our LL
    }else{
        /* similarily if the above condition was false, which means l2's data is either smaller than
        l1 or equal, in both scnarios we can again use the same logic as above*/
        l2->next = MergeTwoSortedLL(l1,l2->next);
        // again function ended because it satisfied one of our base conditions
        return l2; // we again return l2 because it was the first value in our current function call
    }
}


int main()
{
    vector<int> list1 = {1,3,5,7};
    vector<int> list2 = {2,4,6,8};
    Node* l1 = MakeALinkedList(list1);
    Node* l2 = MakeALinkedList(list2); 

    cout<<"The Two sorted lists are : "<<endl;
    DisplayStuff(l1);DisplayStuff(l2);

    cout<<"The one big sorted list of l1 and l2 is: "<<endl;
    DisplayStuff(MergeTwoSortedLL(l1,l2));


}