// Interleave the first half of the queue with second half :-

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void print(queue<int> q){
    cout<<"Queue is :- ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

// using 1 queue :-
void interleave(queue<int> &q){
    queue<int> q1;
    int size = q.size();
    for(int i = 0; i<(size/2); i++){
        q1.push(q.front());
        q.pop();
    }
    while(!q1.empty()){
        q.push(q1.front());
        q1.pop();
        q.push(q.front());
        q.pop();
    }
}

// using 1 stack
void interleave2(queue<int> &q){
    stack<int> s;
    int half = q.size()/2;

    // enter first half in stack
    for(int i = 0; i<half; i++){
        s.push(q.front());
        q.pop();
    }

    // enque first half from stack
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // rotate queue half time
    for(int i = 0; i<half; i++){
        q.push(q.front());
        q.pop();
    }

    // push first half in stack 
    for(int i = 0; i<half; i++){
        s.push(q.front());
        q.pop();
    }

    // enque one from stack and one q.front
    while (!s.empty())  
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }

}



int main(){
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    print(q);
    interleave2(q);
    print(q);

    return 0;
}