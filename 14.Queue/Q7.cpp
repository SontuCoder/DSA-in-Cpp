// K queue in an array :-

#include<iostream>
using namespace std;

class Kqueu{
    public:
    int *arr;
    int *front;
    int *rear;
    int size;
    int *next;
    int freeIndex;

    Kqueu(int s, int n){
        arr = new int[s];
        next = new int[s];
        size = s;
        freeIndex = 0;
        front = new int[n];
        rear = new int[n];
        for(int i = 0; i<n;i++){
            front[i] = rear[i] = -1;
        }
        for(int i = 0; i<s; i++){
            next[i] = i+1;
        }
        next[s-1] = -1;
    }

    void print(){
        cout<<"array :- ";
        for(int i =0; i<size; i++){
            cout<< arr[i]<<" ";
        }cout<<endl;
    }

    void push(int n, int val){
        if(freeIndex == -1){
            cout<<"Array full."<<endl;
            return;
        }
        int index = freeIndex;
        freeIndex = next[index];
        arr[index] = val;
        if(front[n-1] == -1){
            front[n-1] = index;
        } else {
        next[rear[n-1]] = index;
        }
        next[index] = -1;
        rear[n-1] = index;

    }

    void peek(int n){
        if(front[n-1] == -1){
            cout<<"Queue is empty."<<endl;
            return;
        }
        cout<<"element :- "<<arr[front[n-1]]<<endl;
    }

    void pop(int n){
        if(front[n-1]== -1){
            cout<<"Queue is Empty."<<endl;
            return;
        }
        int index = front[n-1];
        front[n-1] = next[index];
        next[index] = freeIndex;
        freeIndex = index; 
        arr[index] = -1;
    }
};

int main(){
    Kqueu q(5,3);
    q.push(1,11);
    q.push(2,12);
    q.push(1,13);
    q.print();
    q.push(3,19);
    q.push(3,15);
    q.print();
    q.pop(1);
    q.pop(3);
    q.print();
    return 0;
}