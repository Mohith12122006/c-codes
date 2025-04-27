#include<iostream>
using namespace std;
#define MAX 10
class Stack {
    int arr[MAX];
    int top;
    public:
    Stack() {
        top =-1;
    }
    bool isFull() {
        return (top == MAX-1);
    }
    bool isEmpty() {
        return (top == -1);
    }
    void push(int data) {
        if(isFull()) {
            cout<<"Stack is OVERFLOW. So insertion is not possible.\n";
            return;
        }
        arr[++top] = data;
        cout<<arr[top]<<" Inserted inside the stack successfully.\n";
    }
    void pop() {
        if(isEmpty()) {
            cout<<"STACK IS UNDERFLOW. NO ELEMENT TO POP\n";
            return;
        }
        cout<<"The popped top element is : "<<arr[top]<<endl;
        top--;
    }
    void peek() {
        if(isEmpty()) {
            cout<<"STACK IS UNDERFLOW.\n";
            return;
        }
        cout<<"The top element is : "<<arr[top]<<endl;
    }
    void display() {
        for(int i = 0;i<top+1;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};
int main() {
    Stack s1;
    for(int i=1;i<=10+1;i++) {
        s1.push(i);
    }
    s1.display();
    s1.peek();
    s1.pop();
    s1.display();
}