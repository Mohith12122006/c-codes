#include<iostream>
using namespace std;
class Array {
    int* arr;
    int size;
    int capacity;
    public:
    Array(int cap,int initialSize = 0,int initialArray[] = NULL) {
        capacity = cap;
        size = initialSize;
        arr = new int[capacity];
        if(initialArray != NULL && initialSize <= capacity) {
            for(int i =0;i<size;i++) {
                arr[i] = initialArray[i];
            }
        }
    }
    void insert(int pos,int ele) {
        if(pos > size || pos < 0) {
            cout<<"Invalid position \n";
            return;
        }
        else {
            for(int i = size;i>pos;i--) {
                arr[i] = arr[i-1];
            }
            arr[pos] = ele;
            cout<<"Successfully inserted : "<<ele<<endl;
            size++;
        }
    }
    void deleteEle(int pos) {
        if(size < 0 || pos>size||pos<0) {
            cout<<"Invalid input\n";
            return;
        }
         cout<<"Successfully Deleted : "<<arr[pos]<<endl;
        for(int i=pos;i<=size-1;i++) {
            arr[i] = arr[i+1];
        }
        size--;
    }
    int search(int ele) {
        for(int i=0;i<size;i++) {
            if(arr[i] == ele) {
                return i;
            }
        }
        return -1;
    }
    void sort() {
        if(size < 0) {
            cout<<"Array is empty\n";
            return;
        }
        for(int i=0;i<size;i++) {
            for(int j = 0;j<size-i-1;j++) {
                if(arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        display();
    }
    void display() {
        if(size < 0) {
            cout<<"Array is empty\n";
            return;
        }
        for(int i=0;i<size;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
};
int main() {
    int n;
    cout<<"Enter the number of maximum elements : ";
    cin>>n;
    int s;
    cout<<"Enter the initial number of element to be inserted : ";
    cin>>s;
    int arr[s];
    cout<<"Enter the elements in the array : \n";
    for(int i=0;i<s;i++) {
        cin>>arr[i];
    }
    Array ADT(n,s,arr);
    ADT.display();
    ADT.insert(4,20);
    ADT.deleteEle(3);
    ADT.display();
    ADT.sort();
}