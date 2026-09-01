#include <bits/stdc++.h>

using namespace std;

/*Complete implementation of AVL tree given in Example 01 by implementing Insert and Delete
methods.*/

class AVLTree {
  private: struct Node {
    int key;
    Node * left;
    Node * right;
    int height;
    Node(int k): key(k), left(nullptr), right(nullptr), height(1) {}
  };

  Node * root;

  int height(Node * node) {
    return node ? node -> height : 0;
  }
  int balanceFactor(Node * node) {
    return node ? height(node -> left) - height(node -> right) : 0;
  }
  void updateHeight(Node * node) {
    node -> height = 1 + max(height(node -> left), height(node -> right));
  }
  Node * rotateRight(Node * y) {
    Node * x = y -> left;
    Node * T2 = x -> right;
    x -> right = y;
    y -> left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
  }
  Node * rotateLeft(Node * x) {
    Node * y = x -> right;
    Node * T2 = y -> left;
    y -> left = x;
    x -> right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
  }
  Node * balance(Node * node) {
    updateHeight(node);
    int balance = balanceFactor(node);
    // Left heavy
    if (balance > 1) {
      if (balanceFactor(node -> left) < 0) // Left-Right case
        node -> left = rotateLeft(node -> left);
      return rotateRight(node); // Left-Left case
    }
    // Right heavy
    if (balance < -1) {
      if (balanceFactor(node -> right) > 0) // Right-Left case
        node -> right = rotateRight(node -> right);
      return rotateLeft(node); // Right-Right case
    }
    return node; // Balanced
  }
  Node * minValueNode(Node * node) {
    Node * current = node;
    while (current && current -> left != nullptr)
      current = current -> left;
    return current;
  }
  Node * insert(Node * node, int key) {
    if (!node) return new Node(key);
    if (key < node -> key)
      node -> left = insert(node -> left, key);
    else if (key > node -> key)
      node -> right = insert(node -> right, key);
    else
      return node; // Duplicate keys not allowed

    //recursive insertion in a bst
    // implement the code
    return balance(node);
  }
  Node * deleteNode(Node * root, int key) {
    // Perform standard BST delete
    // Complete the code
    // Balance the node
    if (!root) return root;
    if (key < root -> key)
      root -> left = deleteNode(root -> left, key);
    else if (key > root -> key)
      root -> right = deleteNode(root -> right, key);
    else {
      // Node with only one child or no child
      if ((!root -> left) || (!root -> right)) {
        Node * temp = root -> left ? root -> left : root -> right;
        if (!temp) { // No child case
          temp = root;
          root = nullptr;
        } else // One child case
          *
          root = * temp; // Copy the contents of the non-empty child
        delete temp;
      } else {
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node * temp = minValueNode(root -> right);
        // Copy the inorder successor's data to this node
        root -> key = temp -> key;
        // Delete the inorder successor
        root -> right = deleteNode(root -> right, temp -> key);
      }
    }
    if (!root) return root;
    return balance(root);
  }
  void inOrder(Node * node) {
    if (!node) return;
    inOrder(node -> left);
    cout << node -> key << " ";
    inOrder(node -> right);
  }
  public: AVLTree(): root(nullptr) {}
  void insert(int key) {
    root = insert(root, key);
  }
  void deleteKey(int key) {
    root = deleteNode(root, key);
  }
  void inOrder() {
    inOrder(root);
    cout << endl;
  }
};
int main() {
  AVLTree tree;
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(20); // Duplicate insertion
  tree.insert(40);
  tree.insert(50);
  tree.insert(25);
  cout << "In-order traversal before deletion: ";
  tree.inOrder();
  tree.deleteKey(20);
  cout << "In-order traversal after deleting 20: ";
  tree.inOrder();
  return 0;
}