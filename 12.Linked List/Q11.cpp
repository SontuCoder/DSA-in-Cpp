// Palindrom LL

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

void print(Node* &head){
    Node* ptr = head;
    cout<<"The list be:- ";
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

void reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* new_node = head;

    while(new_node != NULL){
        new_node = new_node->next;
        curr->next = prev;
        prev = curr;
        curr = new_node;
    }
    head = prev;
}

bool palindrom(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    reverse(slow);

    Node* curr = head;
    while(slow != NULL){
        if(slow->data != curr->data){
            return false;
        }
        slow= slow->next;
        curr = curr->next;
    }
    return true;
}


int main(){
    Node* head1 = new Node(1);
    Node* n2 = new Node(0);
    Node* n3 = new Node(2);
    Node* n4 = new Node(2);
    Node* n5 = new Node(0);
    Node* n6 = new Node(3);

    head1->next =n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    print(head1);
    cout<<"Palindrom :- "<<palindrom(head1);


    return 0;
}