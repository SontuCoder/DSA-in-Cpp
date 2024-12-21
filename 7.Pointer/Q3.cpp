// Pointer and Functions:-

#include<iostream>
using namespace std;

void print(int *p){
    cout<<*p<<endl;
}

void update(int *p){//it pass a address in a pointer, it has risk and best for dynamic size array
    // p = p+1;
    // cout<<"In function:- "<<*p<<endl;
    *p = *p + 1;
}

void update2(int &p){ //it pass as a reference, it is safe and best for fixed size array
    p = p + 1;
}

int main(){
    int value = 3;
    int *p = &value;
    // print(p);

    cout<<"Before update:- "<<*p<<endl;
    update(p);
    cout<<"After update:- "<<*p<<endl;
    update2(*p);
    cout<<"After update2:- "<<*p<<endl;

    return 0;
}


