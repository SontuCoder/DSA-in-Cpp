#include<iostream>
using namespace std;

int main(){
    char name[10];
    cout<<"Enter the name be:- ";
    cin>>name;
    name[2] = '\0';
    cout<<"The name:- "<<name;
    return 0;
}