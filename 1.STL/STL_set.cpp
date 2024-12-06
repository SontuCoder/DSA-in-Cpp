#include<iostream>
#include<set>

using namespace std;

void print(set<int> s){
    for(int i:s){
        cout<<i<<" ";
    }
    cout<<endl;
}

void print1(set<int, greater<int>> s){
    for(int i:s){
        cout<<i<<" ";
    }
    cout<<endl;
}


int main(){

    // Set in Ascending Order by default
    set<int> s;

    // Set in Descending Order
    set<int, greater<int>> s1;

    s.insert(2);
    s.insert(3);
    s.insert(0);
    s.insert(7);
    s.insert(4);
    s.insert(1);

    cout<<"The Elements of set: ";
    print(s);

    cout<<"The S1 is empty:"<<s1.empty()<<endl;

    s1.insert(2);
    s1.insert(3);
    s1.insert(0);
    s1.insert(7);
    s1.insert(4);
    s1.insert(1);

    cout<<"The S1 is empty:"<<s1.empty()<<endl;

    cout<<"The Elements of set: ";
    print1(s1);

    s1.insert(1);

    cout<<"The Elements of set: ";
    print1(s1);

    cout<<"The size of s1 :"<<s1.size()<<endl;

    s1.erase(2);

    cout<<"The Elements of set: ";
    print1(s1);

    cout<<"1 is iin the set:"<<s1.count(1)<<endl;
    cout<<"2 is iin the set:"<<s1.count(2)<<endl;

    set<int>::iterator itr = s1.find(4);
    cout<<"value in iterator:"<<*itr<<endl;

    set<int>::iterator itr1 = s1.find(2);// if value is not in set it return iterator of end element.
    cout<<"value in iterator:"<<*itr1<<endl;

    s1.clear();
    cout<<"The size of s1 :"<<s1.size()<<endl;

    return 0;
}



