// Shallow & Deep copy
// Destructor
// Static keyword

#include<iostream>
#include <cstring>
using namespace std;

class Student{
    public: 
    char *name;

    static int Roll;
    static int updateRoll(){ // static function only assecc static members and it has no this key.
        Roll++;
        return Roll;
    }

    Student(){
        name = new char[100];
    }

    void setName(char name[]){
        strcpy(this->name, name);
    }

    void print(){
        cout<<"Name:- "<<this->name<<endl;
    }

    Student(Student& temp){  // Make Deep copy
        char * ch = new char[strlen(temp.name)+1];
        strcpy(ch, temp.name);
        this->name = ch;
    }

    ~Student(){  // Destructor call automaticlly for static Constructor, But for Dynamic Constructor we manually call Destructor.
        cout<<"Call Destructor"<<endl;
    }

}; 

int Student :: Roll = 5; // Static member initialision ( :: -> Scope Rsolution operator),

int main(){

    // By Default constructor
    char name[6] = "Sontu";
    Student s1;
    s1.setName(name);

    //s1.print();

    // By Copy constructor

    Student s2(s1); // When we use default Copy constructor it use shallow copy 
    //s2.print();

    s1.name[0] = 'G';

    cout<<"\nAfter Update:- \n"<<endl;
    s1.print();
    s2.print();

    s1=s2;  // Copy assignment Operator
    cout<<"\nAfter Copy:- \n"<<endl;
    s1.print();
    s2.print();

    Student *s3 = new Student;
    delete s3; // Manualy destructor call

    cout<<"Static key:- "<<Student::Roll<<endl; // static member belong to class not object

    cout<<"Call static Function:- "<<Student::updateRoll()<<endl;



    return 0;
}