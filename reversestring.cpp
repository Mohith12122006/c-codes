#include<iostream>
#include<stack>
#include<string>
using namespace std;
void reverse_word(string word) {
    stack<char> a;
    for(int i=0;i<word.length();i++) {
        a.push(word[i]);
    }
    cout<<"The reversed word is: ";
    string reversed_word = "";
    while(!a.empty()) {
        reversed_word += a.top();
        a.pop();
    } 
    cout<<"The reversed word is: "<<reversed_word<<endl;
    
}
int main() {
    char choice;
    cout<<"Enter the y : ";
    cin>>choice;
    cin.ignore();
    while(choice == 'y') {
        string word;
        cout<<"Enter the word to be reversed : ";
        getline(cin,word);
        //cin.ignore();
        reverse_word(word);
        cout<<"To continue (y/n): ";
        cin>>choice;
        cin.ignore();
    }
    if( choice != 'y') {
        cout<<"Programe ended\n";
    }
}
