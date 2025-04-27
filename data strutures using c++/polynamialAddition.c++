#include<iostream>
using namespace std;
struct Node {
    int coeff,exp;
    Node* next;
    Node(int c,int e) {
        coeff = c;
        exp = e;
        next = NULL;
    }
};

class Polynomial {
    Node* head;
    public:
    Polynomial() {head = NULL;}
    void insertNode(int c,int e) {
        Node* n = new Node(c,e);
        if(head == NULL || head->exp < e) {
            n->next = head;
            head = n;
            return;
        }
        Node* t = head;
        while(t->next != NULL && t->next->exp > e) {
            t = t->next;
        }
        n->next = t->next;
        t->next = n;
    }

    Polynomial add(Polynomial& poly2) {
        Polynomial result;
        Node* p1 = head;
        Node* p2 = poly2.head;
        while(p1 != NULL && p2 != NULL) {
            if(p1->exp == p2->exp) {
                int sum = p1->coeff + p2->coeff;
                if(sum != 0) {
                    result.insertNode(sum,p1->exp);
                }
                p1 = p1->next;
                p2 = p2->next;
            }
            else if(p1->exp > p2->exp) {
                result.insertNode(p1->coeff,p1->exp);
                p1 = p1->next;
            }
            else {
                result.insertNode(p2->coeff,p2->exp);
                p2 = p2->next;
            }
        }
        while(p1 != NULL) {
            result.insertNode(p1->coeff,p1->exp);
            p1= p1->next;
        }
        while(p2 != NULL) {
            result.insertNode(p2->coeff,p2->exp);
            p2 = p2->next;
        }
        return result;
    }
    void display() {
        if (head == nullptr) {
            cout << "0" << endl;
            return;
        }
        
        Node* current = head;
        bool first = true;
        
        while (current != nullptr) {
            if (!first && current->coeff > 0) {
                cout << " + ";
            }
            
            if (current->coeff != 0) {
                if (current->coeff < 0) {
                    cout << " - ";
                    cout << -current->coeff;
                }
                else {
                    cout << current->coeff;
                }
                
                if (current->exp > 0) {
                    cout << "x";
                    if (current->exp > 1) {
                        cout << "^" << current->exp;
                    }
                }
                first = false;
            }
            current = current->next;
        }
        cout << endl;
    }
    
    // Destructor to free memory
    ~Polynomial() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};
int main() {
    Polynomial p1,p2;
    p1.insertNode(4,2);
    p1.insertNode(2,1);
    p1.insertNode(1,0);
    cout<<"Polynomial 1 : ";
    p1.display();
    p2.insertNode(5,3);
    p2.insertNode(4,2);
    p2.insertNode(3,1);
    p2.insertNode(4,3);
    p2.insertNode(-5,0);
    cout<<"Polynomial 2 : ";
    p2.display();
    Polynomial p3;
    p3 = p1.add(p2);
    cout<<"Result of the addition of two polynomials : "<<endl;
    p3.display();
}