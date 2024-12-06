#include<iostream>
#include<queue>

using namespace std;

int main(){

    // Max Heap
    priority_queue<int> maxHeap;

    cout<<"The queue is empty :"<<maxHeap.empty()<<endl;

    maxHeap.push(1);
    cout<<"The Top: "<< maxHeap.top()<<endl;

    maxHeap.push(4);
    cout<<"The Top: "<< maxHeap.top()<<endl;

    maxHeap.push(2);
    cout<<"The Top: "<< maxHeap.top()<<endl;

    cout<<"The size of queue :"<<maxHeap.size()<<endl;

    maxHeap.pop();
    cout<<"The Top: "<< maxHeap.top()<<endl;
    cout<<"The size of queue :"<<maxHeap.size()<<endl;

    cout<<"The queue is empty :"<<maxHeap.empty()<<endl;

    cout<<"=============================="<<endl;

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    cout<<"The queue is empty :"<<minHeap.empty()<<endl;

    minHeap.push(1);
    cout<<"The Top: "<< minHeap.top()<<endl;

    minHeap.push(4);
    cout<<"The Top: "<< minHeap.top()<<endl;

    minHeap.push(0);
    cout<<"The Top: "<< minHeap.top()<<endl;

    cout<<"The size of queue :"<<minHeap.size()<<endl;

    minHeap.pop();
    cout<<"The Top: "<< minHeap.top()<<endl;
    cout<<"The size of queue :"<<minHeap.size()<<endl;

    cout<<"The queue is empty :"<<minHeap.empty()<<endl;

    return 0;
}