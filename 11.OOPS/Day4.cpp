// 1. Encapsulation


// Encapsulation:- A fully encapsulated class is the one in which all the data members are private and all the member functions are public.

#include<iostream>
using namespace std;

// Encapsulation Example
class Hero{
    private:
    int health;
    int attack;
    int defence;

    public:
    void setHealth(int health){
        this->health = health;
    }

    int getHealth(){
        return health;
    }

};

int main(){
    Hero h1;
    h1.setHealth(100);
    cout<<"Hero Health:- "<<h1.getHealth()<<endl;

    return 0;
}