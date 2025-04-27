#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
    void insert(int val) {
        root = insertNode(val, root);
    }

    void remove(int val) {
        root = deleteNode(root, val);
    }
    Node* insertNode(int val, Node* root) {
    void displayTree() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            cout << val << " inserted successfully.\n";
            return root;
            display(root);
            cout << endl;
        }
            return root;
};
class BST {
    Node* root;
    public:
    BST() {
        root = NULL;
    }
    Node* insertNode(int val,Node* root) {
        Node* n = new Node(val);
    void display(Node* root) {
        if (root == NULL) {
            return;
        }
        if(val == root->data) {
            cout<<"Invalid data.\n";
            return;
        }
        if(val < root->data) {
    Node* deleteNode(Node* root, int val) {
        }
        cout << "Value not found in the tree.\n";
        return root;
    }
        cout<<val<<" inserted successfully.\n";
    }
    void display(Node* root) {
        if(root == NULL) {
            cout<<"Tree is empty.\n";
            return;
        }
        cout<<root->data<<" ";
        display(root->left);
        display(root->right);
        } else if (root->right == NULL) {
    void deleteNode(Node* root,int val) {
        if(root == NULL) {
        cout << "Value not found in the tree.\n";
        return;
    }
    if(val < root->data) {
        deleteNode(root->left, val);
    } else if(val > root->data) {
        deleteNode(root->right, val);
    } else {
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
    }
            root = temp;
        } else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            root = temp;
        } else {
            // Node with two children: Get the inorder successor
            Node* temp = root->right;
            while(temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            deleteNode(root->right, temp->data);
        }
    }
        }

    }
};