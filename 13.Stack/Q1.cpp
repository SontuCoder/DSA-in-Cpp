// two stack in an array:--


#include<iostream>
using namespace std;

class Stack{
    public:
    int top1;
    int top2;
    int *arr;
    int size;

    StackArray(int size){
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    ~StackArray() {
        delete[] arr;
    }

    bool empty(){
        return (top1 == -1 && top2 == size);
    }

    void pop1(){
        if(top == -1){
            cout<<"Stack 1 is empty."<<endl;
            return;
        }
        top1--;
    }

    void pop2(){
        if(top2 == size){
            cout<<"Stack 2 is empty."<<endl;
            return;
        }
        top2++;
    }

    int peek1(){
        if(top1 == -1){
            cout<<"Stack 1 is empty."<<endl;
            return -1;
        }
        return arr[top1];
    }
    int peek2(){
        if(top2 == size){
            cout<<"Stack 2 is empty."<<endl;
            return -1;
        }
        return arr[top2];
    }

    void push1(int value){
        if(top1 + 1  == top2){
            cout<<"Stack is overflow."<<endl;
            return;
        }
        top1++;
        arr[top1] = value;
    }

    void push2(int value){
        if(top1 + 1  == top2){
            cout<<"Stack is overflow."<<endl;
            return;
        }
        top2--;
        arr[top2] = value;
    }

    bool full(){
        return top1 == top2 -1;
    }

    int currentSize() {
        return size - top2 + top1 +1;
    }
};


int main(){
    Stack s(5);
    cout<<"Is empty:- "<<s.empty()<<endl;
    s.push1(1);
    cout<<s.peek1()<<endl;
    cout<<s.peek2()<<endl;
    s.push1(1);
    s.push2(4);
    s.push2(4);
    s.push2(2);
    cout<<"is full:- "<<s.full()<<endl;


    return 0;
}