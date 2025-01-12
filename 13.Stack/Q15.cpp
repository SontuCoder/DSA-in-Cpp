// Special Stack :-

#include<iostream>
#include<stack>
using namespace std;

class StackArray{
    public:
    stack<int> s;
    int mini;

    bool empty(){
        return s.empty();
    }

    int pop(){
        if(s.empty()){
            cout<<"Stack is empty."<<endl;
            return -1;
        }
        int curr = s.top();
        s.pop();
        if(curr>mini){
            return curr;
        } else {
            int prev = mini;
            mini = 2*mini - curr;
            return prev;
        }
    }

    int peek(){
        if(s.empty()){
            cout<<"Stack is empty."<<endl;
            return -1;
        }
        if(s.top()>mini){
            return curr;
        } else {
            return mini;
        }
    }

    void push(int value){
        if(s.empty()){
            s.push(value);
            mini = value;
            return;
        }
        if(value<mini){
            s.push(2*value -mini);
            mini = value;
        } else {
            s.push(value);
        }
    }

    int getMin(){
        if(s.empty()){
            return -1;
        }
        return mini;
    }
};



int main(){
    
    return 0;
}