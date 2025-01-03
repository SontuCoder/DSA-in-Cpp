// Reverse of Link list by recursion :-

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
};

void recurReverse(Node* &head, Node*  curr, Node* prev){
    if(curr == NULL){
        head= prev;
        return;
    }
    Node* currNext = curr->next;
    curr->next = prev;
    prev = curr;
    recurReverse(head, currNext, prev);
}


void reverse(Node* & head){
    if(head == NULL || head->next == NULL){
        return;
    }
    recurReverse(head, head, NULL);
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

    print(head);

    reverse(head);
    print(head);

    return 0;
}