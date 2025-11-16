#include<bits/stdc++.h>
using namespace std;

/*Define following methods in Example 01 by using stack.
o Preorder traversal
o Postorder travsersal*/

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    stack<Node*>s;
    s.push(root);
    while(!s.empty()){
        Node* curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        if(curr->right){
            s.push(curr->right);
        }
        if(curr->left){
            s.push(curr->left);
        }
    }
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    stack<Node*>s1,s2;
    s1.push(root);
    while(!s1.empty()){
        Node* curr=s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left){
            s1.push(curr->left);
        }
        if(curr->right){
            s1.push(curr->right);
        }
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

int main(void){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    cout<<"Preorder Traversal: ";
    preorder(root);
    cout<<endl;

    cout<<"Postorder Traversal: ";
    postorder(root);
    cout<<endl;

    return 0;
}