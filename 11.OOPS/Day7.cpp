// Polimorphism
// Polimorphism is a concept of OOPS in which a single function can be used in different ways.
// There are two types of Polimorphism:
// 1. Compile time Polimorphism
// 2. Run time Polimorphism


#include<iostream>
using namespace std;

// Compile time Polimorphism
// 1. Function Overloading
// 2. Operator Overloading

// Function Overloading
class A{
    public: 
    void add(){
        cout<<"Sum number:- "<<6+5<<endl;
    }

    void add(int a){
        cout<<"Sum one number:- "<<a+5<<endl;
    }
    int add(int a, int b){
        cout<<"Sum of two number:- "<<a+b<<endl;
    }
    // void add(int a, int b){ // this function is not allowed because of same signature.
    //     cout<<"Sum of two number:- "<<a+b<<endl;
    // }

    void add(int a, double b){
        cout<<"Sum of two int and double number:- "<<a+b<<endl;
    }
};

// Operator Overloading
class B
{
    public:
    void operator+(int a){
        cout<<"Subtruct of two number:- "<<a-5<<endl;
    }

    void operator()(){
        cout<<"This is a Bracket."<<endl;
    }
};



// Run time Polimorphism
// 1. Function Overriding

// Function Overriding
class Animal{
    public:
    void eat(){
        cout<<"Animal is eating."<<endl;
    }
};

class Dog: public Animal{
    public:
    void eat(){
        cout<<"Dog is eating."<<endl;
    }
};


int main(){
    
    A a1;
    a1.add();
    a1.add(5);
    a1.add(5, 6);
    a1.add(5, 6.5);

    cout<<"========================"<<endl;
    B b1;
    b1+5;
    b1();

    cout<<"========================"<<endl;
    Dog d1;
    d1.eat();


    return 0;
}