// Inheritance:-

// Inheritance:- It is a mechanism in which one class acquires the properties and behavior of another class. 
// Access Modifiers:- It is a keyword that specifies the access scope of the class members.
// Types of Access Modifiers:-
// 1. Public:- The class members declared as public can be accessed from anywhere in the program.
// 2. Protected:- The class members declared as protected can be accessed by any function of the class and by the functions of the derived class.
// 3. Private:- The class members declared as private can't be accessed from outside the class.

#include<iostream>
using namespace std;

class Human{
    public:
    int age = 10;
    
    protected:
    int weight = 50;

    private:
    int height = 5.5;

};

class Male : public Human{
    
    public:
    int id = 1;

    int getWeight(){
        return weight;
    }

    // int getHeight(){
    //     return height;
    // }

};

class Female : protected Human{
    public:
    int id = 2;

    int getAge(){
        return age;
    }

    int getWeight(){
        return weight;
    }

    // int getHeight(){
    //     return height;
    // }
};

class Child : private Human{
    public:
    int id = 3;

    int getAge(){
        return age;
    }

    int getWeight(){
        return weight;
    }

    // int getHeight(){
    //     return height;
    // }
};


int main(){

    cout<<"=============== Access  in Public Mode =============="<<endl;
    Male m1;
    cout<<m1.age<<endl;
    // cout<<m1.weight<<endl; // it is protected so it is accessable.
    cout<<m1.getWeight()<<endl; // it is protected so it is accessable.
    // cout<<m1.height<<endl; // it is private so it is not accessable.
    // cout<<m1.getHeight()<<endl; // it is private so it is not accessable.

    cout<<"=============== Access  in Protacted Mode =============="<<endl;
    Female f1;
    // cout<<f1.age<<endl; // it is protected so it is not accessable.
    cout<<f1.getAge()<<endl; // it is protected so it is not accessable.
    // cout<<f1.weight<<endl; // it is protected so it is not accessable.
    cout<<f1.getWeight()<<endl; // it is protected so it is not accessable.
    // cout<<f1.height<<endl; // it is private so it is not accessable.
    // cout<<f1.getHeight()<<endl; // it is private so it is not accessable.
    
    cout<<"=============== Access  in Private Mode =============="<<endl;
    Child c1;
    // cout<<c1.age<<endl; // it is private so it is not accessable.
    cout<<c1.getAge()<<endl; // it is private so it is not accessable.
    // cout<<c1.weight<<endl; // it is private so it is not accessable.
    cout<<c1.getWeight()<<endl; // it is private so it is not accessable.
    // cout<<c1.height<<endl; // it is private so it is not accessable.
    // cout<<c1.getHeight()<<endl; // it is private so it is not accessable.
    
    return 0;
}