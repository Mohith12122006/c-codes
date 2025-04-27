#include<iostream>
#include<stack>
#include<string>
using namespace std;
string reverseString(string s) {
    stack<char> c;
    for (char ch : s) {
        c.push(ch);
    }
    
    string reversed = "";
    while (!c.empty()) {
        reversed += c.top();
        c.pop();
    }
    
    return reversed;
}
int main() {
    string normal;
    cout<<"Enter the string : ";
    getline(cin,normal);
    string rev = reverseString(normal);
    cout<<"The reversed string is : "<<rev<<endl;
}