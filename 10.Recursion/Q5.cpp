// IO:- 3,2 => 3^2

#include<iostream>
using namespace std;

// takes O(n)
int power(int i,int j){
    if(j==0) return 1;
    return i*power(i,j-1);
}

// takes O(log n)
int power2(int i, int j){
    if(j==0) return 1;
    if(j==1) return i;

    int ans = power2(i, j/2);

    if(j%2){
        return i*ans*ans;
    } else {
        return ans*ans;
    }
}


int main(){
    int i, j;
    cout<<"Enter the numbers:-"<<endl;
    cin>>i>>j;
    cout<<"Ans:- "<<power2(i,j);
    return 0;
}