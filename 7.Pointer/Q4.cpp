// Double Pointer


#include<iostream>
using namespace std;

int main(){
    int a = 4;
    int *p = &a;
    int **p1 = &p;// Double pointer to save pointer's pointer.
    cout<<**p1<<endl;// print value's value;

    int ***p2 = &p1;
    cout<<***p2<<endl; 
    return 0;
}