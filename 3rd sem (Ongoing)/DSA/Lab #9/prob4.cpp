#include <bits/stdc++.h>
using namespace std;

/*Given the root of a binary search tree, recursively find the sum of all nodes of the tree.*/

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val) {
            data = val;
            left = nullptr;
            right = nullptr;
        }
};

int sumOfNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    int totalSum = sumOfNodes(root);
    cout << "Sum of all nodes: " << totalSum << endl;

    return 0;
}