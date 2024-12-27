// Class & Object :-

#include<iostream>
using namespace std;

// Place larger data types first in your structures.Forces the compiler to minimize or eliminate padding, but may reduce performance on some architectures.

#pragma pack(1) // to open pack
// create Class
class Hero{
    
    bool dance; // we can't access dance property because the "public:" after it.
    // we can access health and level.
    
    public: // by default access modifier be privet. 
    int health; // property
    char level;

    private:
    int weight = 89;
    
    public: // getter  and setter must be public
    int getWeight(){ // getter helps to get private property of a object.
        return weight;
    }

    void setWeight(int i){ // setter helps to set value in private 
        weight = i;
    }

};
#pragma pack() // Toclose pack



int main(){
    
    Hero h1; //create object

    cout<<"Size of object:-"<<sizeof(h1)<<endl; // size of object = sum( properties of object)
    // size of empty class be 1;(for identification of the object.)
    
    h1.health = 34;
    h1.level = 'A';
    cout<<"The health of hero: "<<h1.health<<endl;
    cout<<"The level of hero: "<<h1.level<<endl;

    // access private property by getter 
    cout<<"Get element by getter:- "<<h1.getWeight()<<endl;

    h1.setWeight(98); // set value in private property

    cout<<"Get element by getter:- "<<h1.getWeight()<<endl;

    return 0;
}