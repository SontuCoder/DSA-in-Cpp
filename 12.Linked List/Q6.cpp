// Remove duplicate in sorted LL:-

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    Node(int value){
        this->data = value;
        this->next = NULL;
    }

    ~Node(){
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void removeDuplicate(Node* &head){
    if(head == NULL || head->next == NULL) return;
    Node* curr = head;
    while(curr != NULL){
        if(curr->next != NULL  && curr->data == curr->next->data){
            Node* ptr = curr->next;
            curr->next = ptr->next;
            ptr->next = NULL;
            delete ptr;
        } else {
            curr = curr->next;
        }
    }
}

void print(Node* &head){
    Node* ptr = head;
    cout<<"The list be:- ";
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}


int main(){

    Node * head = new Node(1);
    Node * n2 = new Node(1);
    Node * n3 = new Node(3);
    Node * n4 = new Node(3);
    Node * n5 = new Node(5);
    Node * n6 = new Node(6);

    head->next =n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    print(head);
    removeDuplicate(head);
    print(head);
    
    return 0;
}