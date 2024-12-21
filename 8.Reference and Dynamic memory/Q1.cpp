// reference variable:-

#include<iostream>
using namespace std;

void update(int i){
    i++;
}

void update1(int &i){
    i++;
}


int &add(int i){ // its very dengerious it gives us warning... same for pointer don't return any pointer.
    int &num = i;
    num++;
    return num;
}

int main(){
    int i = 5;
    int &j = i; // create reference variable( Same memori but different name)

    cout<< i << endl;
    i++;
    cout<< i << endl;
    j++;
    cout<< i << endl;
    cout<< j << endl;
    cout<<"======================"<<endl;

    update(i);
    cout<<"In pass by value:- "<< i << endl;
    update1(i);
    cout<<"In pass by reference:- "<< i << endl;

    // Return a reference :- 
    cout<<add(i)<<endl;



    return 0;
}