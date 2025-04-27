#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node* next;
    node(int value) {
        data = value;
        next = nullptr;
    }
};
typedef node* Node;
class SLL {
    Node first;
    public:
    SLL() {
        first = NULL;
    }
    void insertAtBeg(int val) {
        Node n = new node(val);
        n->next = first;
        first = n;
        cout<<val<<" inserted successfully at the beginning\n";
    }
    void insertAtLast(int val) {
        Node n = new node(val);
        if(first == NULL) {
            first = n;
            cout<<"Inserted at the beginning\n";
            return;
        }
        Node t = first;
        while(t->next!=NULL) {
            t = t->next;
        }
        t->next = n;
        cout<<val<<" successfully inserted at the last\n";
    }
    int countNodes() {
        int count = 0;
        Node t = first;
        while(t != NULL) {
            count++;
            t=t->next;
        }
        return count;
    }
    void insertAtPos(int pos,int val) {
        int count = countNodes();
        if(first == NULL && pos > 0 || count == 0 || pos <= 0) {
            cout<<"List is empty. So insertion is not possible.\n";
            return;
        }
        if(pos == 1) {
            insertAtBeg(val);
            return;
        }
        
        Node n = new node(val);
        Node t = first;
        for(int i = 1 ; i < pos-1 && t != NULL ;i++) {
            t = t->next;
        }
        if(t == NULL) {
            cout<<"Postion out of range\n";
            return;
        }
        n->next = t->next;
        t->next = n;
        cout<<val<<" inserted successfully at the pos"<<pos<<endl;
    }
    void deleteAtBeg() {
        if(first == NULL) {
            cout<<"List is empty. So deletion is not possible\n";
            return;
        }
        Node t = first;
        cout<<"Deleted the first element : "<<first->data<<endl;
        first = first->next;
        delete t;
    }
    void deleteAtLast() {
        if(first == NULL) {
            cout<<"List is empty. So deletion is not possible\n";
            return;
        }
        Node t = first;
        Node tp = NULL;
        while(t->next != NULL) {
            tp = t;
            t =t->next;
        }
        cout<<"Delted the last node : "<<t->data<<endl;
        tp->next = NULL;
        delete t;
    }
    void deleteAtpos(int pos) {
        if(first == NULL && pos > 0|| pos<=0) {
            cout<<"Invalid position so insertion is not possible\n";
            return;
        }
        int count = countNodes();
        if(pos <= count ) {
            if(pos == 1) {
                deleteAtBeg();
                return;
            }
            Node t = first;
            for(int i=1;i<pos-1 && t != NULL;i++) {
                t = t->next;
            }
            if(t == NULL) {
                cout<<"Postion out of bounds\n";
                return;
            }
            cout<<"Deleted the element"<<t->next->data<<endl;
            Node tp = t->next;
            t->next = tp->next;
            delete tp;
        }
    }
    void deletionByValue(int value) {
        if(first == NULL) {
            cout<<"List is not empty. So deletion is not possible\n";
            return;
        }
        if(first->data == value) {
            deleteAtBeg();
            return;
        }
        Node t = first;
        while(t->next->data != value && t->next != NULL) {
            t = t->next;
        }
        if (t->next == nullptr) {
            cout<<"Value not found\n";
            return;
        }
        cout<<"Deleted : "<<t->next->data<<endl;
        Node tp = t->next;
        t->next = tp->next;
        delete tp;
        
    }
        void searhNode(int val) {
            if(first == NULL) {
                cout<<"List is empty\n";
                return;
            }
            Node t = first;
            int i = 0;
            while(t->data != val && t != NULL) {
                i++;
                t =t->next;
            }
            if(t == NULL) {
                cout<<"Element is not found\n";
                return;
            }
            cout<<"The element is found at the postion : "<<i<<endl;
        }
        void display() {
            Node t = first;
            while(t != nullptr) {
                cout<<t->data<<"->";
                t = t->next;
            }
            cout<<"END\n";
        }

};
int main() {
    SLL s;
    s.insertAtBeg(12);
    s.insertAtLast(14);
    s.insertAtPos(2,13);
    for(int i = 11;i<16;i++) {
        s.insertAtLast(i);
    }
    s.display();
    cout<<"no of nodes : "<<s.countNodes()<<endl;
    s.deleteAtBeg();
    s.deleteAtLast();
    s.deleteAtpos(4);
    cout<<"No of nodes present : " <<s.countNodes()<<endl;
    s.display();
    s.deletionByValue(14);
    s.display();
    
}