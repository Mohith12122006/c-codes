#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CLL {
    Node* front;
public:
    CLL() { front = NULL; }
    
    void insertatBeg(int val) {
        Node* n = new Node(val);
        if(front == NULL) {
            front = n;
            front->next = front;
            cout<<"Inserted successfully.\n";
            return;
        }
        Node* t = front;
        do {
            t = t->next;
        } while(t->next != front);
        t->next = n;
        n->next = front;
        front = n;
        cout<<"Inserted successfully.\n";
    }
    
    void insertAtLast(int val) {
        Node* n = new Node(val);
        if(front == NULL) {
            front = n;
            front->next = front;
            cout<<"Inserted successfully.\n";
            return;
        }
        Node* t = front;
        do {
            t = t->next;
        } while(t->next != front);
        t->next = n;
        n->next = front;
        cout<<"Inserted successfully.\n";
    }
    
    void display() {
        if(front == NULL) {
            cout<<"List is empty.\n";
            return;
        }
        cout<<"Displaying the list : ";
        Node* t = front;
        do {
            cout<<t->data<<"-->";
            t = t->next;
        } while(t != front);
        cout<<"End\n";
    }
    
    int countNodes() {
        if(front == NULL) return 0;
        Node* t = front;
        int i = 0;
        do {
            t = t->next;
            i++;
        } while(t != front);
        return i;
    }
    
    void insertAtMiddle(int pos, int val) {
        if(pos < 1) {
            cout<<"Invalid position.\n";
            return;
        }
        
        int count = countNodes();
        if(pos == 1) {
            insertatBeg(val);
            return;
        }
        if(pos > count + 1) {
            cout<<"Position out of bounds.\n";
            return;
        }
        if(pos == count + 1) {
            insertAtLast(val);
            return;
        }
        
        Node* n = new Node(val);
        int i = 1;
        Node* t = front;
        while(i < pos - 1) {
            i++;
            t = t->next;
        }
        n->next = t->next;
        t->next = n;
        cout<<"Inserted Successfully.\n";
    }
    
    void deleteAtBeg() {
        if(front == NULL) {
            cout<<"List is empty. No elements to delete\n";
            return;
        }
        
        if(front->next == front) {
            cout<<"Deleted : "<<front->data<<endl;
            delete front;
            front = NULL;
            return;
        }
        
        Node* t = front;
        Node* last = front;
        while(last->next != front) {
            last = last->next;
        }
        
        cout<<"Deleted : "<<front->data<<endl;
        front = front->next;
        last->next = front;
        delete t;
    }
    
    void deleteAtLast() {
        if(front == NULL) {
            cout<<"List is empty. No elements to delete\n";
            return;
        }
        
        if(front->next == front) {
            cout<<"Deleted : "<<front->data<<endl;
            delete front;
            front = NULL;
            return;
        }
        
        Node* t = front;
        Node* prev = NULL;
        while(t->next != front) {
            prev = t;
            t = t->next;
        }
        prev->next = front;
        cout<<"Deleted : "<<t->data<<endl;
        delete t;
    }
    void deletionByPos(int pos) {
        int count = countNodes();
        if(front == NULL ) {
            cout<<"List is empty.Deletion is not possible.\n";
            return;
        }
        if(pos == 1) {
            deleteAtBeg();
            return;
        }
        if(pos == count+1) {
            deleteAtLast();
            return;
        }
        if(pos > count+1) {
            cout<<"Position out of bounds.\n";
            return;
        }
        Node* t = front;
        int i = 0;
        do {
            i++;
            if(i == pos-1) {
                break;
            }
            t = t->next;
        } while(t->next != front);
        Node* tp = t->next;
        t->next = tp->next;
        cout<<"Deleted : "<<tp->data<<endl;
        delete tp;
        
    }
};

int main() {
    CLL c1;
    c1.insertatBeg(10);
    c1.insertatBeg(89);
    c1.display();
    c1.insertAtLast(78);
    c1.insertAtLast(76);
    c1.display();
    c1.insertAtMiddle(2,45);
    c1.insertAtMiddle(4,56);
    c1.display();
    c1.deleteAtBeg();
    c1.display();
    c1.deleteAtLast();
    c1.display();
    cout<<"The number of nodes in the list is : "<<c1.countNodes()<<endl;
    c1.deletionByPos(c1.countNodes());
    c1.display();
    return 0;
}