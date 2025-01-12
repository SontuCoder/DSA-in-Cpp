// N stack in an array

#include <iostream>
using namespace std;

class NStack {
public:
    int *arr;       // Array to store actual elements
    int *top;       // Array to store the index of top element for each stack
    int *next;      // Array to store the next available spot for each stack
    int n, s, freeSpot;


    // Constructor to initialize the data structures
    NStack(int N, int S) {

        n=N;
        s=S;
        arr = new int[s];

        // make top array with start index -1;
        top = new int[n];
        for(int i = 0; i<n; i++){
            top[i] =  -1;
        }

        next =  new int[s];
        for(int i = 0; i<s; i++){
            next[i] =  i+1;
        }
        next[s-1] = -1;
        freeSpot = 0;
    }

    // Push element into stack number `stackNum`
    void push(int stackNum, int value) {
        
        // check stack overfloow
        if(freeSpot == -1){
            cout<<"Array is full.";
            return;
        }

        // 1 take free index 
        int index = freeSpot;

        // 2 update free index
        freeSpot = next[index];

        // 3 insert in Array
        arr[index] = value;
        
        // 4 update next
        next[index] = top[stackNum-1];

        // 5 update top 
        top[stackNum -1] = index;
    }

    // Pop element from stack number `stackNum`
    int pop(int stackNum) {
        // check stack empty
        if(top[stackNum-1] == -1){
            cout<<"Stack is empty";
            return -1;
        }
        
        // fatch index

        int index = top[stackNum-1];

        // update top
        top[stackNum-1]= next[index];

        // fetch value
        int value = arr[index];

        // update next
        next[index] = freeSpot;

        //update free
        freeSpot = index;

        return value;

    }
};

void print(int *a, int n){
    for(int i = 0; i<n; i++){
        cout<<a[i]<<" ";
    } 
    cout<<endl;
}

int main() {
    NStack stacks(3, 10); // 3 stacks, array of size 10

    stacks.push(1, 10);
    stacks.push(1, 20);
    stacks.push(3, 30);

    
    cout<<"top : ";
    print(stacks.top, 3);

    cout<<"next : ";
    print(stacks.next, 10);

    cout<<"freeSpot :- "<<stacks.freeSpot<<endl;

    stacks.push(1, 20);
    stacks.push(2, 30);

    
    stacks.push(1, 20);
    stacks.push(3, 30);

    cout<<"top : ";
    print(stacks.top, 3);

    cout<<"next : ";
    print(stacks.next, 10);

    cout<<"freeSpot :- "<<stacks.freeSpot<<endl;

    return 0;
}
