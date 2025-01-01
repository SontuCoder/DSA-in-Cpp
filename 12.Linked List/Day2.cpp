// Doubli Linklist


#include<iostream>
using namespace std;

class Node{
    public:
    Node* prev;
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Inserting:- 
void insert(int value, Node* &head, int pos){
    Node* temp = new Node(value);
    if(pos == 1){
        temp->next = head;
        if (head != NULL) {
            head->prev = temp;
        }
        head = temp;
        return;
    }
    Node* ptr = head;
    int i = 1;

    while(i<pos-1 && ptr!=NULL){
        i++;
        ptr= ptr->next;
    }

    if(ptr==NULL){
        cout<<"Position out of range."<<endl;
        delete temp;
        return;
    }
    if(ptr->next == NULL){
        ptr->next = temp;
        temp->prev = ptr;
        return;
    }
    ptr->next->prev = temp;
    temp->prev = ptr;
    temp->next = ptr->next;
    ptr->next = temp;
}

// Print 
void print(Node * head){
    Node * ptr = head;
    cout<<"The Doubli linklist:- ";
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int main(){
    Node* head = new Node(23);
    print(head);
    insert(10,head,1);
    print(head);
    insert(12,head,3);
    print(head);
    return 0;
}