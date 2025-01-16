// reverse a Queue :-

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void print(queue<int> q){
    cout<<"Queue is :- ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

// Approch 1 (Using Stack)
void reverse(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

// Approch 2 (recurtion)
void reverse2(queue<int> &q){
    if(q.empty()) return;
    int a = q.front();
    q.pop();
    reverse2(q);
    q.push(a);
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    print(q);
    // reverse(q);
    // print(q);
    reverse2(q);
    print(q);
    return 0;
}