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

Node* firstLoop(Node* noob, Node* pro){
    while(noob!= pro){
        pro= pro->next;
        noob= noob->next;
    }
    return pro;
}

Node* firstNodeLoop(Node* &head){
    if(head == NULL) return NULL;

    Node* pro = head;
    Node* noob = head;
    while(pro != NULL && pro->next != NULL){
        pro= pro->next->next;
        noob= noob->next;
        if(pro == noob){
            return firstLoop(head, pro);
        }
    }
    return NULL;
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
    cout<<"Loop Start:- "<<firstNodeLoop(head)->data<<endl;
    
    return 0;
}