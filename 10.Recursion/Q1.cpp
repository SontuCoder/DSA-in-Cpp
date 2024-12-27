// When the solution of a Big/complex problem depends on the solution of a same type small problem then we use "Recursion".

// Recursion has :-
                //   Base case 
                //   Recursion Relation
                //   Processing (Optional)


#include<iostream>
using namespace std;

int fact(int n){

    // Base case (In base case return is mandatory)
    if(n<0) return -1;
    if(n==0 || n==-1){
        return 1;
    } 
    // Recursion relation
    else {
        return n*fact(n-1);
    }
}

int main(){
    cout<<fact(5);
    return 0;
}