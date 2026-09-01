#include <bits/stdc++.h>
using namespace std;

/*You are tasked with designing an employee management system for a small company. Each
employee has a unique ID, name, and department. You are required to store and manage employee
records in a way that allows quick insertion, deletion, and search operations based on the employee
ID. You decide to use a Binary Search Tree (BST) to store the employee records. Each node in the BST
will store: Employee ID (used as the key for the BST), Employee Name, Employee Department.
- Create a C++ class EmployeeNode representing each employee in the BST. Each node should store:
int id (Employee ID), string name (Employee Name), string department (Employee Department), A
pointer to the left child (EmployeeNode* left), a pointer to the right child (EmployeeNode* right).
- Create a class EmployeeBST with the following member functions:

o insert(int id, string name, string department): Inserts a new employee into the BST.
o search(int id): Searches for an employee by ID. If found, return their name and
department; otherwise, print an appropriate message.
o deleteNode(int id): Deletes an employee from the BST based on their ID.
o inOrderTraversal(): Prints all employees in ascending order of their ID, showing their ID,
name, and department.
o findMin(): Returns the name and department of the employee with the smallest ID.
o findMax(): Returns the name and department of the employee with the largest ID.
- Also, Handle edge cases such as: Inserting an employee with a duplicate ID, Deleting an employee
that does not exist, Deleting nodes with no children, one child, and two children, Handling an
empty tree for search or delete operations.*/


class EmployeeNode {
    public:
        int id;
        string name;
        string department;
        EmployeeNode* left;
        EmployeeNode* right;
    EmployeeNode(int empId, string empName, string empDept) {
        id = empId;
        name = empName;
        department = empDept;
        left = nullptr;
        right = nullptr;
    }
};

class EmployeeBST {
    private:
        EmployeeNode* root;

        EmployeeNode* insert(EmployeeNode* node, int id, string name, string department) {
            if (node == nullptr) {
                return new EmployeeNode(id, name, department);
            }
            if (id < node->id) {
                node->left = insert(node->left, id, name, department);
            } else if (id > node->id) {
                node->right = insert(node->right, id, name, department);
            } else {
                cout << "Employee with ID " << id << " already exists." << endl;
            }
            return node;
        }

        EmployeeNode* search(EmployeeNode* node, int id) {
            if (node == nullptr || node->id == id) {
                return node;
            }
            if (id < node->id) {
                return search(node->left, id);
            }
            return search(node->right, id);
        }

        EmployeeNode* deleteNode(EmployeeNode* node, int id) {
            if (node == nullptr) {
                cout << "Employee with ID " << id << " does not exist." << endl;
                return node;
            }
            if (id < node->id) {
                node->left = deleteNode(node->left, id);
            } else if (id > node->id) {
                node->right = deleteNode(node->right, id);
            } else {
                if (node->left == nullptr) {
                    EmployeeNode* temp = node->right;
                    delete node;
                    return temp;
                } else if (node->right == nullptr) {
                    EmployeeNode* temp = node->left;
                    delete node;
                    return temp;
                }
                EmployeeNode* temp = findMinNode(node->right);
                node->id = temp->id;
                node->name = temp->name;
                node->department = temp->department;
                node->right = deleteNode(node->right, temp->id);
            }
            return node;
        }
        EmployeeNode* findMinNode(EmployeeNode* node) {
            EmployeeNode* current = node;
            while (current && current->left != nullptr) {
                current = current->left;
            }
            return current;
        }
        EmployeeNode* findMaxNode(EmployeeNode* node) {
            EmployeeNode* current = node;
            while (current && current->right != nullptr) {
                current = current->right;
            }
            return current;
        }
        void inOrderTraversal(EmployeeNode* node) {
            if (node != nullptr) {
                inOrderTraversal(node->left);
                cout << "ID: " << node->id << ", Name: " << node->name << ", Department: " << node->department << endl;
                inOrderTraversal(node->right);
            }
        }
    public:
        EmployeeBST() {
            root = nullptr;
        }
        void insert(int id, string name, string department) {
            root = insert(root, id, name, department);
        }
        void search(int id) {
            EmployeeNode* result = search(root, id);
            if (result != nullptr) {
                cout << "Employee Found - ID: " << result->id << ", Name: "

                        << result->name << ", Department: " << result->department << endl;
            } else {
                cout << "Employee with ID " << id << " not found." << endl;
            }
        }
        void deleteNode(int id) {
            root = deleteNode(root, id);
        }
        void inOrderTraversal() {
            inOrderTraversal(root);
        }
        void findMin() {
            EmployeeNode* minNode = findMinNode(root);
            if (minNode != nullptr) {
                cout << "Employee with Minimum ID - ID: " << minNode->id << ", Name: " << minNode->name << ", Department: " << minNode->department << endl;
            } else {
                cout << "The tree is empty." << endl;
            }
        }
        void findMax() {
            EmployeeNode* maxNode = findMaxNode(root);
            if (maxNode != nullptr) {
                cout << "Employee with Maximum ID - ID: " << maxNode->id << ", Name: " << maxNode->name << ", Department: " << maxNode->department << endl;
            } else {
                cout << "The tree is empty." << endl;
            }
        }
};

int main() {
    EmployeeBST bst;
    bst.insert(101, "Alice", "HR");
    bst.insert(102, "Bob", "Engineering");
    bst.insert(103, "Charlie", "Marketing");

    cout << "In-order Traversal of Employees:" << endl;
    bst.inOrderTraversal();

    bst.search(102);
    bst.search(105);

    bst.findMin();
    bst.findMax();

    bst.deleteNode(102);
    cout << "After deleting employee with ID 102:" << endl;
    bst.inOrderTraversal();

    bst.deleteNode(105);

    return 0;
}