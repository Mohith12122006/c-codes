#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
// Function to check precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}
// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    for (char c : infix) {
        if (isalnum(c)) {
            // If the character is an operand, add it to the postfix expression
            postfix += c;
        } else if (c == '(') {
            // If the character is '(', push it onto the stack
            s.push(c);
        } else if (c == ')') {
            // If the character is ')', pop and append until '(' is encountered
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove '(' from the stack
        } 
        else if (isOperator(c)) {
            // If the character is an operator
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);    
        }
    }
    // Pop all remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}
float evaluation(string postfix) {
    stack<float> s;
    for (char c : postfix) {
        if (isdigit(c)) {
            // If the character is a digit, push it onto the stack
            s.push(c - '0');
        } else if (isOperator(c)) {
            // If the character is an operator, pop two elements and apply the operator
            float b = s.top(); s.pop();
            float a = s.top(); s.pop();
            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    
    // The final result will be at the top of the stack
    return s.top();
}
int main() {
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin,infix);
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    float evaluate = evaluation(postfix);
    cout<<"The evaluate postfix is : "<<evaluate<<endl;

    return 0;
}