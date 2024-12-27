#include<iostream>
#include<map>
using namespace std;

void print(map<int,string> m){
    for(auto i:m){           
        // we 
        cout<<i.first<<" : "<<i.second<<endl;
    }
    cout<<endl;
}

void print1(const map<int, string, greater<int>> m) {
    for (auto pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << endl;
}

int main(){

    map<int,string> m;// Default map store Sorted key Ascending order,

    m[1]="Benw";
    m[2]="And";
    m[3]="Bsjd";
    m[4]="Cjkdn";
    m[5]="Ojkd";
    print(m);

    map<int, string, greater<int>> m1; // Descending order

    m1[2] = "Two";
    m1[1] = "One";
    m1[3] = "Three";
    m1[5] = "Five";
    m1[4] = "Four";

    cout<<"HI"<<m1[1][0];

    cout << "The Elements of the map (Descending):" << endl;
    print1(m1);

    m1.insert({6,"Hi"});
    cout << "The Elements of the map (Descending):" << endl;
    print1(m1);

    m1.insert({6,"Hello"});  // second Ignored
    cout << "The Elements of the map (Descending):" << endl;
    print1(m1);

    m1.erase(6);  // second Ignored
    cout << "The Elements of the map (Descending):" << endl;
    print1(m1);

    m1.insert({6,"Hello"});  // second Ignored
    cout << "The Elements of the map (Descending):" << endl;
    print1(m1);

    cout<< "The key 5 present or not: "<<m1.count(5)<<endl;

    return 0;
}