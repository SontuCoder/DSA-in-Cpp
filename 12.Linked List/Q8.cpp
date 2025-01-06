// Marge Sort

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

Node* margeLL(Node* head1, Node* head2){
    if(!head1) return head2;
    if(!head2) return head1;

    Node* head = nullptr;
    if(head1->data>head2->data){
        head = head2;
        head2 = head2->next;
    } else {
        head = head1;
        head1 = head1->next;
    }
    
    Node* ptr = head;
    while(head1!=NULL && head2 != NULL){
        if(head1->data < head2->data){
            ptr->next = head1;
            head1 = head1->next;
        } else {
            ptr->next = head2;
            head2 = head2->next;
        }
        ptr = ptr->next;
    }
    if(head1 != NULL){
        ptr->next = head1;
    }
    if(head2 != NULL){
        ptr->next = head2;
    }
    return head;
}

Node* mid(Node* head){

    Node* fast = head->next;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* sortLL(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* middle = mid(head);
    Node* nextNode = middle->next;
    middle->next = NULL;

    Node* left = sortLL(head);
    Node* right = sortLL(nextNode);

    return margeLL(left, right);
}


int main(){

    Node* head1 = new Node(4);
    Node* n2 = new Node(1);
    Node* n3 = new Node(4);
    Node* n4 = new Node(3);
    Node* n5 = new Node(7);
    Node* n6 = new Node(2);

    head1->next =n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    print(head1);
    Node* head = sortLL(head1);
    print(head);
    
    return 0;
}