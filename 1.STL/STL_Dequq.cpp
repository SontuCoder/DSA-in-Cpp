#include<iostream>
#include<deque>
using namespace std;

void print(deque<int> d){
    for(int i: d){
        cout<<i<<" ";
    } 
    cout<<endl;
}

int main(){

    deque<int> d;
    cout<<"The deque d is empty: "<<d.empty()<<endl;

    deque<int> d1 = {1,3,2,5,3,6};
    cout<<"The deque d1 is empty: "<<d1.empty()<<endl;
    cout<<"The d1: ";
    print(d1);

    d.push_front(1);
    d.push_back(3);
    d.push_front(4);
    cout<<"The d : ";
    print(d);

    cout<<"The size of d :"<<d.size()<<endl;
    cout<<"The capacity of d: "<<d.max_size()<<endl;
    cout<<"The capacity of d1: "<<d1.max_size()<<endl;

    d1.resize(3);
    cout<<"The d1: ";
    print(d1);
    cout<<"The size of d1 :"<<d1.size()<<endl;
    cout<<"The capacity of d1: "<<d1.max_size()<<endl;

    d1.resize(10,5);
    cout<<"The d1: ";
    print(d1);
    cout<<"The size of d1 :"<<d1.size()<<endl;

    cout<<"The element in index 2 of d1 :"<<d1.at(2)<<endl;

    d.pop_front();
    cout<<"The d : ";
    print(d);

    d.pop_back();
    cout<<"The d : ";
    print(d);

    cout<<"The element in front of d1 :"<<d1.front()<<endl;

    cout<<"The element in end of d1 :"<<d1.back()<<endl;

    d.insert(d.begin()+1,31);
    cout<<"The d : ";
    print(d);

    d.insert(d.begin()+1,30);
    cout<<"The d : ";
    print(d);

    d.insert(d.begin()+1,3,9); // (pos, count, val)
    cout<<"The d : ";
    print(d);

    d.erase(d.begin()+4);
    cout<<"The d : ";
    print(d);

    d.erase(d.begin()+1,d.begin()+3); // [start, end)
    cout<<"The d : ";
    print(d);

    d.clear();
    cout<<"The d : ";
    print(d);

    d.swap(d1);
    cout<<"The d : ";
    print(d);
    
    return 0;
}