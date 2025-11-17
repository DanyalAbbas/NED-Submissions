#include <bits/stdc++.h>
using namespace std;

/*Complete implementation of AVL tree given in Example 01 by implementing Insert and Delete
methods.*/

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        key = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int height(Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}
int getBalance(Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
