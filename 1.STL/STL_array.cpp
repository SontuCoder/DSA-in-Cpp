#include<iostream>
#include<array>
using namespace std;

int main(){

    // It is same as normal array. here "a" is an array of length 5.
    array<int,5> a = {2,1,3,5,4};

    int n = a.size(); // for length
    cout<<endl <<"Array length: "<<n<< endl;

    // using for access element by index
    cout<<"Element at index 1 : "<<a.at(1)<< endl;

    // STL Array empty or not
    cout<<"Array is empty : "<<a.empty()<< endl;

    // First element of STL array:
    cout<<"First Element of array: "<<a.front()<< endl;

    // Last element of STL array:
    cout<<"Last Element of array: "<<a.back()<< endl;

    cout<<"All Elements in a: ";
    for(int i:a){
        cout<<i<<" ";
    } 
    cout<<endl;

    a.fill(10); // all elements become 10

    cout<<"All Elements in a: ";
    for(int i:a){
        cout<<i<<" ";
    } 
    cout<<endl;

    array<int, 5> arr2 = {6, 7, 8, 9, 10}; // in swap the size must be same.
    a.swap(arr2);

    cout<<"All Elements in a: ";
    for(int i:a){
        cout<<i<<" ";
    } 
    cout<<endl;

// All Oparetion on O(1)

    return 0;
}