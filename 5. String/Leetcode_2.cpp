// Print the length of string:-
#include<iostream>
using namespace std;

int main(){
    char name[10];
    cout<<"Enter the name be:- ";
    cin>>name;
    cout<<"The name:- "<<name<<endl;
    int n =0;
    while(name[n]!='\0'){
        n++;
    }
    cout<<"The length of name:- "<<n;
    return 0;
}