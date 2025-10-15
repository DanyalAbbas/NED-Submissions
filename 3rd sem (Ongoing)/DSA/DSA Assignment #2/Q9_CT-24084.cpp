#include <bits/stdc++.h>
using namespace std;

/*Implement a queue's enqueue and dequeue operations using only two stacks.*/


class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    cout<<obj->peek()<<endl;
    cout<<obj->pop()<<endl; 
    cout<<obj->empty()<<endl; 
    return 0;
}