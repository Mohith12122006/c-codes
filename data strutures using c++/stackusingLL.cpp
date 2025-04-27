#include<iostream>
using namespace std;
#define Max 10
struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};
class Stack{
    Node* top;
    public:
    Stack() {
        top = NULL;
    }
    bool isEmpty() {return top==NULL;}    
    void push(int val) {
        Node* n = new Node(val);
        if(isEmpty()) {
            top = n;
            cout<<n->data<<" Successfully inserted in the stack\n";
            return;
        }
        n->next = top;
        top = n;
        cout<<n->data<<" Successfully inserted in the stack\n";
    }
    void pop() {
        if(isEmpty()) {
            cout<<"Stack is underflow. Popping is not possible\n";
            return;
        }
        Node* t = top;
        cout<<"The popped element is : "<<top->data<<endl;
        top=top->next;
        delete(t);
    }
    void display() {
        Node* t = top;
        if(isEmpty()) {
            cout<<"Stack is underflow\n";
            return;
        }
        while( t != NULL) {
            cout<<t->data<<"->";
            t=t->next;
        }
        cout<<"End\n";
    }
};
int main() {
    Stack s;
    s.push(12);
    s.push(78);
    s.display();
    s.pop();
    s.display();
}