#include<iostream>
using namespace std;
struct node {
    int data;
    node* next;
    node(int v) {
        data = v;
        next = NULL;
    }
};
typedef struct node* Node;
class Queue {

    Node front;
    Node rear;
    public:
    Queue() {
        front = rear = NULL;
    }
    void enqueue(int v) {
        Node n = new node(v);
        if(front == NULL) {
            cout<<v<<"inserted successfully\n";
            front = n;
            rear = n;
            return;
        }
        rear->next = n;
        rear = n;
        cout<<v<<"inserted successfully\n";
    }
    void display() {
        if(front == NULL) {
            cout<<"Queue is underflow.\n";
            return;
        }
        rear = front;
        while(rear != NULL) {
            cout<<rear->data<<"->";
            rear = rear->next;
        }
        cout<<"END\n";
    }
    void pop() {
        if(front == NULL) {
            cout<<"Queue is underflow.\n";
            return;
        }
        cout<<front->data<<" popped successfully.\n";
        Node t = front;
        if(front->next == NULL) {
            delete t;
            front = NULL;
            return;
        }
        front = front->next;
        delete t;
    }
    void peek() {
        if(front == NULL) {
            cout<<"Queue is underflow.\n";
            return;
        }
        cout<<front->data<<" is the peek element.\n";
    }

};
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.pop();
    q.peek();
    q.display();
}