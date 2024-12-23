// Macro

#include<iostream>  // <iostream>  (our main hader file) .
                    //  #include -> Preprocessor directive. copy/refer all header files in our code before compile.
using namespace std;

// create Macro (A piece of code in aprogram that is replaced bu value of macro.)
// It doesn't take memory. Before compile code it replace the value of PI every where in code by 3.14; we can't change its value.
#define PI 3.14 // Object-Like Macros

#define HEIGHT WIDTH // 
#define WIDTH 20    // Chain Macro

#define ELE 1,\
            2,\
            3

#define AREA(r) (r*r)
#define MIN(a, b) (((a) < (b)) ? (a) : (b))



int main(){
    
    double pi = 3.14; // It takes memory. And we can change the value of it.

    cout<<PI<<endl;
    cout<<WIDTH<<endl;
    cout<<HEIGHT<<endl;
    
    int arr[] = { ELE };
    printf("Elements of Array are:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d  ", arr[i]);
    } cout<<endl;

    cout<<"The area be:- "<<AREA(2)<<endl;
    cout<<"MIN of them "<<MIN(4,3)<<endl;
    
    return 0;
}