#include<iostream>
#include<list>

using namespace std;

void print(list<int> d){
    for(int i: d){
        cout<<i<<" ";
    } 
    cout<<endl;
}

int main(){

    // List created using Doubly Linkedlist.
    list<int> l={3,4,22,2};
    list<int> l1;
    list<int> l2{98,24,43,124,2,9};
    list<int> l3(4,5);
    cout<<"The l: ";
    print(l);
    cout<<"The l1: ";
    print(l1);
    cout<<"The l2: ";
    print(l2);
    cout<<"The l3: ";
    print(l3);


    // size(), empty(), max_size(), front(), back(), 
    // push_back(), push_front(), pop_back(), pop_front(),
    // insert(), erase(), clear(), swap(), resize(), 
    // use as deque...


    return 0;
}