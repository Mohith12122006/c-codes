#include <iostream>
#include <stack>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    
    return root;
}
void inorderTraversal(Node* root) {
    stack<Node*> s;
    Node* curr = root;
    while(curr != NULL || !s.empty()) {
        while(curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->data<<"-->";
        curr = curr->right;
    }
    cout<<"END\n";
}
void preOrderTraversal(Node* root) {
    if (root == nullptr) return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        cout << current->data <<"-->";

        if (current->right) s.push(current->right);
        if (current->left) s.push(current->left);
    }
    cout <<"END"<< endl;
}
void postOrerTraversal(Node* root) {
    if(root == NULL) {
        return;
    }
    stack<Node*>s,d;
    s.push(root);
    while(!s.empty()) {
        Node* curr = s.top();
        s.pop();
        d.push(curr);
        if(curr->left) s.push(curr->left);
        if(curr->right) s.push(curr->right);
    }
    while(!d.empty()) {
        cout<<d.top()->data<<"-->";
        d.pop();
    }cout<<"END"<<endl;
}
int main() 
{
    Node* root = NULL;
    root = insertNode(root,50);
    root = insertNode(root,30);
    root = insertNode(root,40);
    root = insertNode(root,20);
    root = insertNode(root,70);
    root = insertNode(root,60);
    root = insertNode(root,80);
    
    cout<<"Preorder Traversal : ";
    preOrderTraversal(root);
    cout<<"Post-Order Traversal: ";
    postOrerTraversal(root);
    cout<<"Inorder Traversal: ";
    inorderTraversal(root);
}