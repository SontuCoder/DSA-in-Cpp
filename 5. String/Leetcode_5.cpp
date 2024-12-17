// string:- 

#include<iostream>
using namespace std;

int main(){
    string s = "Sontu";
    cout<<s<<endl;
    cout<<s.length()<<endl;
    cout<<s.size()<<endl; 
    cout<<s.capacity()<<endl; // minimum size asign 15
    cout<<s.max_size()<<endl;
    s.resize(3);
    cout<<s<<endl;
    s.resize(s.length()+4,'h');
    cout<<s<<endl;
    s.clear();
    cout<<s.empty()<<endl;
    s.append("ab");
    s.append("a");// can add multiple char and use double cotation.
    cout<<s<<endl;
    s.push_back('d'); // can push single char and use single cotation.
    cout<<s<<endl;
    s.assign(2,'*');
    cout<<s<<endl;
    s.insert(1,"so");
    cout<<s<<endl;
    s.pop_back();
    cout<<s<<endl;
    return 0;
}