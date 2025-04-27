#include<iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements in the array : ";
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    cout<<"Entered array is : ";
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"The sorted array using bubble sort algorithm : ";
    for(int i=-0;i<n-1;i++) {
        for(int j =0;j<n-i-1;j++) {
            if(a[j]>a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter the element to search its postion : ";
    int k,i;
    cin>>k;
    cout<<"Using linear search the position found is : ";
    for(i=0;i<n;i++) {
        if(a[i]==k) {
            cout<<"The element found at the position : "<<i+1<<endl;
            break;
        }
    }
    if(i==n) {
        cout<<"Element not found\n";
    }

}