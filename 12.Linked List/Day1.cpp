// Create Node 
// Create Singliy linked List
// Insert (front, end, mid / any position)
// delete (any position)
// print

#include<iostream>
using namespace std;

// Node create
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// Insert

void insertNodeHead(int data, Node* &head){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertNodeTail(int data, Node* &tail){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertNodeMid(int data, Node* &head, Node* &tail, int pos){
    if(pos == 1){
        insertNodeHead(data,head);
        return;
    }
    Node* ptr = head;
    int i = 1;
    while(i<pos-1 && ptr!=NULL){
        ptr = ptr->next;
        i++;
    }
    if(ptr==NULL){
        cout<<"Position is not in range"<<endl;
        return;
    }
    if(ptr->next == NULL){
        insertNodeTail(data,tail);
        return;
    }
    Node* temp = new Node(data);
    temp->next = ptr->next;
    ptr->next = temp;
}

// Delete

void deleteNode(int pos, Node* &head, Node* &tail){
    if(head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* ptrPrev = head;
    if(pos==1){
        head = ptrPrev->next;
        if(head == NULL){
            tail = NULL;
        }
        delete ptrPrev;
        return;
    }
    Node* curr = head->next;
    int i = 1;
    while(i<pos-1 && curr!=NULL){
        i++;
        ptrPrev=curr;
        curr=curr->next;
    }
    if(curr == NULL){
        cout<<"Position Out of range."<<endl;
        return;
    }
    if(curr->next == NULL){
        tail= ptrPrev;
        ptrPrev->next = NULL;
        delete curr;
        return;
    }
    ptrPrev->next = curr->next;
    delete curr;
}


//Print

void print(Node* &head){
    Node* temp = head;
    cout<<"The Linked list be:- ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main(){

    Node * n1 = new Node(10);
    Node* head = n1;
    Node* tail = n1;

    print(head);

    insertNodeHead(11,head);
    insertNodeHead(12,head);
    insertNodeHead(13,head);
    insertNodeHead(14,head);
    insertNodeHead(15,head);

    print(head);


    insertNodeTail(20,tail);
    insertNodeTail(21,tail);
    insertNodeTail(22,tail);
    insertNodeTail(23,tail);
    insertNodeTail(24,tail);

    print(head);

    insertNodeMid(100,head, tail, 2);
    insertNodeMid(101,head, tail, 1);

    print(head);

    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;

    cout<<"\n ========== Delete ==========="<<endl;
    deleteNode(1,head,tail);
    print(head);

    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;

    deleteNode(2,head,tail);
    print(head);

    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;

    deleteNode(11,head,tail);
    print(head);

    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;

    
    return 0;
}