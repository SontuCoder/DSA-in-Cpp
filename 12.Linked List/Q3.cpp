// Detech Loop in LL

#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    Node(int value){
        this->data = value;
        this->next = NULL;
    }
};

void print(Node* &head){
    Node* ptr = head;
    cout<<"The list be:- ";
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

// Normal Approach:-
bool detechLoop(Node* &head){
    if(head == NULL ) return false;

    map<Node*, bool> m;
    Node* ptr = head;
    while(ptr!= NULL){
        if(m[ptr]== true){
            return true;
        }
        m[ptr] = true;
        ptr= ptr->next;

        // if(m.find(ptr) == m.end()){
        //     m[ptr] = true;
        //     ptr= ptr->next;
        // } else {
        //     return true;
        // }
    }
    return false;
}


// Floyd's cycle detection algo:-

bool floydDetech(Node* &head){
    if(head == NULL ) return false;

    Node* noob = head;
    Node* pro = head;

    while(pro!= NULL && pro->next != NULL){
        pro = pro->next->next;
        noob = noob->next;
        if(pro == noob){
            return true;
        }
    }
    return false;
}


int main(){

    Node * head = new Node(1);
    Node * n2 = new Node(2);
    Node * n3 = new Node(3);
    Node * n4 = new Node(4);
    Node * n5 = new Node(5);
    Node * n6 = new Node(6);

    head->next =n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n3;

    // print(head);
    cout<<"Loop exist or not :- "<<detechLoop(head)<<endl;
    cout<<"Loop exist or not By Floyd :- "<<floydDetech(head)<<endl;
    
    return 0;
}