#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};
class BST {
    Node* root;
    public:
    BST() {
        root = NULL;
    }
    Node* insertNode(Node* node,int d) {
        if(node == NULL) {
            cout<<"Successfully inserted : "<<d<<endl;
            return new Node(d);
        }
        if(d < node->data) {
            node->left = insertNode(node->left,d);
        }
        else if(d > node->data) {
            node->right = insertNode(node->right,d);
        }
        return node;
    }
    Node* findMin(Node* node) {
        if(node == NULL) return NULL;
        while(node != NULL && node->left != NULL) {
            node = node->left;
        }
        return node;
    }
    Node* deleteNode(Node* node,int key) {
        if(node == NULL) {
            return NULL;
        }
        if(key < node->data) {
            node->left = deleteNode(node->left,key);
        }
        else if(key > node->data) {
            node->right = deleteNode(node->right,key);
        }
        else {
            //for the node having one child and no child
            if(node->left == NULL) {
                Node* temp = node->right;
                cout<<"Deleted : "<<key<<endl;
                delete node;
                return temp;
            }
            else if(node->right == NULL) {
                Node* temp = node->left;
                cout<<"Deleted : "<<key<<endl;
                delete node;
                return temp;
            }
            else {
                // for the nodes having two childs
                Node* temp = findMin(node->right);
                cout<<"Deleted : "<<temp->data<<endl;
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        
        return node;
    }
    void preorder(Node* node) {
        if(node == NULL) return;
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }
    Node* search(Node* node,int key) {
        if(node == NULL || node->data == key) {
            return node;
        }
        else if(key < node->data) {
            return search(node->left,key);
        }
        else {
            return search(node->right,key);
        }
        return node;
    }
    void insert(int val) {
        root = insertNode(root,val);
    }
    void preorderTraversal() {
        preorder(root);
        cout<<endl;
    }
    void Delete(int key) {
        root = deleteNode(root,key);
    }
    void searchNode(int key) {
        Node* available = search(root,key);
        if(available == NULL) {
            cout<<"The element is not available.\n";
            return;
        }
        else {
            cout<<"The element is found.\n";
        }
    }
};
int main() {
    BST t;
    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(40);
    t.insert(60);
    t.insert(80);
    t.preorderTraversal();
    t.Delete(50);
    t.preorderTraversal();
    t.searchNode(80);
}