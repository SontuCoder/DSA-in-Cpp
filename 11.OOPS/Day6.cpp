// Types of Inheritance:-
// 1. Single Inheritance
// 2. Multiple Inheritance
// 3. Multilevel Inheritance
// 4. Hierarchical Inheritance
// 5. Hybrid Inheritance


#include<iostream>
using namespace std;

class A{
    public:
        void display(){
            cout<<"Class A"<<endl;
        }
};

class B: public A{
    public:
        void hello(){
            cout<<"Class B"<<endl;
        }
};

class C: public B{
    public:
        void hi(){
            cout<<"Class C"<<endl;
        }
};

class D: public A{
    public:
        void bye(){
            cout<<"Class D"<<endl;
        }
};

class E{
    public:
        void hey(){
            cout<<"Class E"<<endl;
        }
};

class F: public A, public E{
    public:
        void baby(){
            cout<<"Class F"<<endl;
        }
};

class G: public A, public E{
    public:
        void kuchu(){
            cout<<"Class G"<<endl;
        }
};

int main(){

    cout<<"============ In class A ============="<<endl;
    A a;
    a.display();


    // Multilevel Inheritance
    cout<<"============ In class B ============="<<endl;
    B b; 
    b.display();
    b.hello();
    
    // Multilevel Inheritance
    cout<<"============ In class C ============="<<endl;
    C c;
    c.display();
    c.hello();
    c.hi();

    // Single Inheritance
    cout<<"============ In class D ============="<<endl;
    D d;
    d.display();
    d.bye();

    // Multiple Inheritance
    cout<<"============ In class F ============="<<endl;
    F f;
    f.display();
    f.hey();
    f.baby();

    // Hybrid Inheritance
    cout<<"============ In class G ============="<<endl;
    G g;
    g.display();
    g.kuchu();
    g.hey();


    return 0;
}