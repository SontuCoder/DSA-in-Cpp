// Static & Dynamic object:-
// Contructor


#include<iostream>
using namespace std;

class Boy{

    private:
    int weight=10;

    public:
    int height = 5;

    // constructor will call automaticlly when we create the object.

    Boy(){  // Default constuctor, It is created default but when we create it manually then the default constructor is deleted.
        cout<<"Call Default Constructor"<<endl;
    }

    Boy(int weight){ // Paramiterised constructor
        // cout<<"Call Parameterised Constructor:- "<<this->weight<<endl;
        this->weight = weight;
        // cout<<"Call Parameterised Constructor:- "<<this->weight<<endl;
    }

    Boy(Boy &temp){ // Copy constuctor, It is created default but when we create it manually then the default Copy constructor is deleted.
        this->height = temp.height;
        this->weight = temp.weight;
    }

    void print(){
        cout<<"weight:- "<<weight<<endl;
    }
};

int main(){

    /* 
    // static object create
    Boy b;
    cout<<"Static access:- "<<b.height<<endl;;

    // Dynamic object create
    Boy *b1 = new Boy;
    cout<<"Dynamic access:- "<<b1->height<<endl;
    cout<<"Dynamic access:- "<<(*b1).height<<endl;
    */

    /*
    //  Call Default constuctor
    Boy b1;
    Boy *b2 = new Boy;

    // call parametarised constructor
    Boy b4(40);
    b4.print();

    Boy *b3 = new Boy(30);
    b3->print();

    // call Copy constructor
    Boy kocha(50);
    kocha.print();

    Boy Rubi(kocha); // call copy
    Rubi.print();
    */
    

    return 0;
}



