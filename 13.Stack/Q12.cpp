// The calibraty problem :-

#include<iostream>
#include<stack>
using namespace std;

// Aprroch 1 :- 
int detach(int a[3][3], int n){
    for(int i=0; i<n; i++){
        int count = 0;
        int celi = 0;
        for(int j=0; j<n; j++){
            if(i != j && a[i][j] == 1){
                count ++;
            }
        }
        for(int j = 0; j<n; j++){
            if(i != j && a[j][i] == 0){
                celi++;
            }
        }
        if(count == 0 && celi == 0){
            return i;
        }
    }
    return -1;
}

// Aprroch 2 :- 

int detach2(int a[3][3], int n){
    stack<int> s;

    // push all elements in stack
    for(int i = 0; i<n; i++){
        s.push(i);
    }

    // get 2 elements and compare
    while(s.size() >1){
        int k = s.top();
        s.pop();

        int l = s.top();
        s.pop();

        if(a[k][l] == 1){
            s.push(l);
        } else {
            s.push(k);
        }
    }

    // check rows
    int last = s.top();
    for(int i = 0; i<n; i++){
        if(i != last && a[last][i] == 1){
            return -1;
        }
    }

    // check columns
    for(int i = 0; i<n; i++){
        if(i != last && a[i][last] == 0){
            return -1;
        }
    }
    return last;
}


int main(){
    int a[3][3] = {{0,1,0}, {0, 0, 0},{0, 1, 0}};
    cout<<"Calibraty :- "<<detach2(a,3);
    return 0;
}