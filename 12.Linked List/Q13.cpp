// Clone LL Node{ data, next* , random* }

#include<iostream>
#include<map>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* random;

    Node(int value){
        this->data = value;
        this->next = NULL;
        this->random = NULL;
    }
};

void print(Node* &head){
    Node* ptr = head;
    cout<<"The list be:- \n";
    while(ptr != NULL){
        cout<<ptr->data<<" : ";
        if(ptr->random){
        cout<<ptr->random->data;
        } else {
            cout<<"0";
        }
        ptr = ptr->next;
        cout<<endl;
    }
    cout<<endl;
}

// Approch 1 :- O(n) time and memory...
Node* clone(Node* head){
    if (head == NULL) {
        return NULL;
    }

    map<Node*, Node*> m;
    Node* oldHead = head;
    Node* head1 = new Node(head->data);
    Node* ptr = head1;
    while(head != NULL){
        m[head] = head1;
        head = head->next;
        if(head == NULL){
            break;
        }
        Node* temp = new Node(head->data);
        head1->next = temp;
        head1 = head1->next;
    }
    while(oldHead != NULL){
        m[oldHead]->random = m[oldHead->random];
        oldHead= oldHead->next;
    }
    return ptr;
}

// Approch 2 :-
Node* clone2(Node* head){
    if (head == NULL) {
        return NULL;
    }

    Node* ptr = head;
    while(ptr != NULL){
        Node* temp = new Node(ptr->data);
        temp->next = ptr->next;
        ptr->next = temp;
        ptr = ptr->next->next;
    }
    Node* oldHead = head;

    while(oldHead != NULL){
        if(oldHead->next != NULL){
            oldHead->next->random = oldHead->random ? oldHead->random->next : oldHead->random;
        }
        oldHead = oldHead->next->next;
    }
    Node* tempNew = head->next;
    while(head != NULL){
        Node* temp = head->next;
        head->next = temp->next;
        head = temp->next;
        if(head){
            temp->next = head->next;
        } else {
            temp->next = NULL;
        }
    }
    return tempNew;
}


int main(){
    Node* head1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    head1->next =n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    head1->random = n4;
    n4->random = n6;
    n6->random = n3;
    n5->random = n2;

    print(head1);
    Node* head = clone2(head1);
    print(head);

    return 0;
}