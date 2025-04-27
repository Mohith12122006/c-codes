#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node* next;
    node* prev;
    node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};
typedef node* Node;
class DLL {
    Node first;
    public:
    DLL() {
        first = NULL;
    }
    void insertBeg(int val) {
        Node n = new node(val);
        n->next = first;
        if (first != NULL) {
            first->prev = n;
        }
        first = n;
        cout<<val<<" inserted at the beginning successfully\n";
    }
    void insertLast(int val) {
        Node n = new node(val);
        if(first == NULL) {
            first = n;
            return;
        }
        Node t = first;
        while(t->next != NULL) {
            t = t->next;
        }
        t->next = n;
        n->prev = t;
        cout<<val<<" inserted at the last successfully\n";
    }
    int countNodes() {
        Node t = first;
        int count = 0;
        while(t != NULL) {
            count++;
            t = t->next;
        }
        return count;
    }
    void insertAtPos(int pos,int val) {
        Node n = new node(val);
        int count = countNodes();
        if(first == NULL && pos >= 1 || pos > count || pos<0) {
            cout<<"Unable to insert Try again later\n";
            return;
        }
        if(pos == 1) {
            insertBeg(val);
            return;
        }
        Node t = first;
        for(int i = 1; i<pos-1 && t != NULL;i++) {
            t = t->next;
        }
        n->next = t->next;
        if (t->next != NULL) {
            t->next->prev = n;
        }
        n->prev = t;
        t->next = n;
        cout<<val<<" inserted successfully at the position "<<pos<<endl;
    }
    void display() {
        Node t = first;
        while( t != NULL) {
            cout<<t->data<<"-->";
            t = t->next;
        }
        cout<<"END\n";
    }
    void deleteBeg() {
        cout<<"Deleted the first node : "<<first->data<<endl;
        Node t = first;
        if(first->next == NULL) {
            Node t = first;
            first = NULL;
            delete t;
            return;
        }
        first = first->next;
        t->next = NULL;
        first->prev = NULL;
        delete(t);
    }
    void deleteLast() {
        if (first == NULL) {
            cout << "List is empty, nothing to delete.\n";
            return;
        }
        if (first->next == NULL) {
            cout << "Deleted the last element: " << first->data << endl;
            delete first;
            first = NULL;
            return;
        }
        Node t = first;
        while (t->next != NULL) {
            t = t->next;
        }
        cout << "Deleted the last element: " << t->data << endl;
        t->prev->next = NULL;
        delete t;
    }
    void deleteAtpos(int pos) {
        if(first == NULL) {
            cout<<"List is empty. So deletion is not possible.\n";
            return;
        }
        if(pos ==1) {
            deleteBeg();
            return;
        }
        int count = countNodes();
        Node t = first;
        for(int i = 1; i<pos-1 && t!=NULL;i++) {
            t = t->next;
        }
        if(t ->next == NULL || pos > count) {
            cout<<"Invalid position. so deletion is not possible.\n";
            return;
        }
        Node toDelete = t->next;
        cout<<"Deleted the node "<<toDelete->data<<" at the position "<<pos<<endl;
        if(toDelete->next == NULL) {
            toDelete->prev->next = NULL;
        } else {
            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;
        }
        delete toDelete;
        
    }
    void searchNode(int val) {
        if(first == NULL) {
            cout<<"List is empty. No items to display\n";
            return;
        }
        Node t = first;
        int i = 0;
        while(t != NULL) {
            i++;
            if(t->data == val) {
                cout<<"the element is found at the position : "<<i<<endl;
                return;
            }
            t = t->next;
        }
        if(t == NULL) {
            cout<<"The element is not found\n";
            return;
        }
    }
};
int main() {
    DLL dll;
    dll.insertBeg(13);
    dll.insertBeg(21);
    dll.insertLast(67);
    dll.insertLast(56);
    dll.insertAtPos(3,45);
    dll.display();
    dll.deleteBeg();
    dll.display();
    dll.deleteLast();
    dll.display();
    dll.deleteAtpos(2);
    dll.display();
    dll.searchNode(7);
}