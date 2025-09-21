#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        string url;
        Node *next;
        Node *prev;
        Node(string x): url(x), prev(nullptr), next(nullptr) {}
};

class BrowserHistory {
    Node *head = nullptr;
public:
    BrowserHistory(string homepage) {
        Node *temp = new Node(homepage);
        temp->next=head;
        head = temp;

    }
    
    void visit(string url) {
        Node *temp = new Node(url);
        head->next = temp;
        temp->prev = head;
        head = temp;
    }
    
    string back(int steps) {
        Node *temp = head;
        while(temp && temp->prev && steps != 0) {temp=temp->prev;steps--;}
        head= temp;
        return head->url;
    }
    
    string forward(int steps) {
        Node *temp = head;
        while(temp && temp->next && steps != 0) {temp=temp->next;steps--;}
        head= temp;
        return head->url;
    }
};


int main() {
    BrowserHistory* obj = new BrowserHistory("leetcode.com");
    obj->visit("google.com");
    obj->visit("facebook.com");
    obj->visit("youtube.com");
    cout<<obj->back(1)<<endl;
    cout<<obj->back(1)<<endl;
    cout<<obj->forward(1)<<endl;
    obj->visit("linkedin.com");
    cout<<obj->forward(2)<<endl;
    cout<<obj->back(2)<<endl;
    cout<<obj->back(7)<<endl;
}