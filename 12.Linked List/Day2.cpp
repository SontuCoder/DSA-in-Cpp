// Doubli Linklist
// Create Node 
// Create Doubli linked List
// Insert (any position)
// delete (any position)
// print
// Length
// Reverse


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

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Free "<<value<<endl;
    }
};

// Inserting:- 
void insert(int value, Node* &head, Node* &tail, int pos){
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
        tail = temp;
        return;
    }
    ptr->next->prev = temp;
    temp->prev = ptr;
    temp->next = ptr->next;
    ptr->next = temp;
}

// Delete :-

void deleteNode(int pos, Node* &head, Node* &tail){
    if(head == NULL){
        cout<<"The Linked list is empty."<<endl;
        return;
    }
    if(pos == 1){
        Node* ptr = head;
        head = head->next;
        head->prev = NULL;
        ptr->next = NULL;
        ptr->prev = NULL;
        delete ptr;
        if(head == NULL){
            tail=NULL;
        }
        return;
    }
    int i = 1;
    Node* ptr = head;
    Node* ptrPrev = nullptr;
    while(i<pos && ptr!=NULL){
        i++;
        ptrPrev = ptr;
        ptr = ptr->next;
    }
    if(ptr==NULL){
        cout<<"The Linked list is empty."<<endl;
        return;
    }
    if(ptr->next == NULL){
        ptrPrev->next = NULL;
        ptr->next = NULL;
        ptr->prev = NULL;
        delete ptr;
        tail=ptrPrev;
        return;
    }

    ptrPrev->next = ptr->next;
    ptr->next->prev = ptrPrev;
    ptr->next = NULL;
    ptr->prev = NULL;
    delete ptr;
}

// Print 
void print(Node* &head){
    Node * ptr = head;
    cout<<"The Doubli linked list:- ";
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

// Length :-

int lengthOfLinkedList(Node* &head){
    if(head == NULL){
        return 0;
    }
    Node* ptr = head;
    int i = 1;
    while(ptr->next != NULL){
        i++;
        ptr= ptr->next;
    }
    return i;
}

// Reverse:-

void reverse(Node* &head, Node* &tail){
    if(head == NULL || head->next == NULL){
        tail = head;
        return;
    }
    tail = head;
    Node* new_node;
    Node* curr;
    Node* ptr = NULL;
    new_node = curr = head;
    while(new_node->next!=NULL){
        new_node = new_node->next;
        curr->next = ptr;
        curr->prev = new_node;
        ptr = curr;
        curr = new_node;
    }
    ptr->prev = NULL;
    head = ptr;
}



int main(){
    Node* head = new Node(23);
    Node* tail = head;
    print(head);
    insert(10,head,tail,1);
    insert(12,head,tail,3);
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    insert(16,head,tail,3);
    insert(13,head,tail,3);
    insert(14,head,tail,3);
    insert(11,head,tail,3);
    insert(15,head,tail,3);
    
    print(head);
    deleteNode(8,head, tail);
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    print(head);

    cout<<"Length:- "<<lengthOfLinkedList(head)<<endl;
    reverse(head,tail);
    print(head);

    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;

    return 0;
}