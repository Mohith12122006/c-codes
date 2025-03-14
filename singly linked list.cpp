#include<iostream>
using namespace std;
struct node {
    int data;
    struct node* next;
};
typedef struct node* Node;
class sll {
    Node first;
    public:
    sll() : first(NULL) {}
    Node createNode() {
        Node n = new node();
        int x;
        cout<<"Enter the number : ";
        cin>>x;
        n->data = x;
        n->next = NULL;
        return n;
    }
    void ins_beg() {
        Node n = createNode();
        if(first == NULL) {
            first = n;
            return;
        }
        n->next = first;
        first = n;
        cout<<"The element is inserted at the beginning.\n";
    }void display() {
        if(first == NULL) {
            cout<<"The list is empty.\n";
            return;
        }
        else {
            Node t = first;
            while(t != NULL) {
                cout<<t->data<<"-->";
                t=t->next;
            }
            cout<<"End\n";
        }
    }

    
};
int main() {
    sll s;
    s.ins_beg();
    s.display();

}