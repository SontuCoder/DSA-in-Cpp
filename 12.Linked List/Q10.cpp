// Sort 0,1,2 in LL :-

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
            this->next = NULL;
        }
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

void sortLL(Node* &head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    while(curr != NULL){
        if(curr->data == 0){
            zeroTail->next = curr;
            zeroTail= zeroTail->next;
        } else if(curr->data == 1) {
            oneTail->next = curr;
            oneTail= oneTail->next;
        } else {
            twoTail->next = curr;
            twoTail= twoTail->next;
        }
        curr = curr->next;
    }

    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }else {
        zeroTail->next = twoHead->next;
    }
    
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
}


int main(){
    Node* head1 = new Node(1);
    Node* n2 = new Node(0);
    Node* n3 = new Node(2);
    Node* n4 = new Node(0);
    Node* n5 = new Node(2);
    Node* n6 = new Node(1);

    head1->next =n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    print(head1);
    sortLL(head1);
    print(head1);

    return 0;
}