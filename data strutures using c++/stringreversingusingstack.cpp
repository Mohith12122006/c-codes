#include<iostream>
#include<string>
#include<stack>
using namespace std;
string reversedString(string normal) {
    string reversed = "";
    stack<char>s;
    for(char ch:normal) {
        s.push(ch);
    }
    while(!s.empty()) {
        reversed += s.top();
        s.pop();
    }
    return reversed;
}
int main() {
    string normal;
    cout<<"Enter the string to be reversed : ";
    getline(cin,normal);
    cout<<"The reversed string is : "<<reversedString(normal)<<endl;
    return 0;
}