#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node* next;
    node* prev;
    node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
        }
};
typedef class node* Node;
class dll {
    Node first;
    public: 
    dll() {
        first = NULL;
    }
    Node createNode(int value) {
        Node n = new node(value);
        n->next = NULL;
        n->prev = NULL;
        return n;
    }
    void ins_beg(int value) {
        Node n = createNode(value);
        if(first == NULL) {
            first = n;
            return;
        first->prev = n;
        first = n;
        n->next = first;
    }
    void display() {
        Node t = first;
        if(first == NULL) {
            cout<<"The list is empty.\n";
            return;
        }
        while()
    }

};

