#include<iostream>
#include<queue>

using namespace std;


int main(){
    queue<int>q;

    cout<<"The queue is empty :"<<q.empty()<<endl;

    q.push(1);
    cout<<"The Top: "<< q.front()<<endl;
    cout<<"The back: "<< q.back()<<endl;

    q.push(4);
    cout<<"The Top: "<< q.front()<<endl;
    cout<<"The back: "<< q.back()<<endl;

    q.push(2);
    cout<<"The Top: "<< q.front()<<endl;
    cout<<"The back: "<< q.back()<<endl;


    cout<<"The size of queue :"<<q.size()<<endl;

    q.pop();
    cout<<"The Top: "<< q.front()<<endl;
    cout<<"The size of queue :"<<q.size()<<endl;

    cout<<"The queue is empty :"<<q.empty()<<endl;

    return 0;
}