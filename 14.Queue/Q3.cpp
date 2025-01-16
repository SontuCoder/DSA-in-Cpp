// Reverse First K elements of a Queue :-

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
void reverse(queue<int> &q, int k){
    stack<int> s;
    int i = 0;
    while(i<k){
        s.push(q.front());
        q.pop();
        i++;
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    while(k<q.size()){
        k++;
        q.push(q.front());
        q.pop();
    }
}



int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    print(q);
    reverse(q,4);
    print(q);
    return 0;
}