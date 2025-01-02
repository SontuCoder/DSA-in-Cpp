// Circular Singly Linked List :-
// Create Node 
// Create Singliy linked List
// Insert (front, end, mid / any position)
// delete (any position)
// print
// Length
// Reverse

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
    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Free "<<value<<" "<<endl;
    }
};

// Insert

void insertNodeHead(int data, Node* &head, Node* &tail) {
    Node* temp = new Node(data);
    if(head == NULL) {
        head = temp;
        tail = temp;
        temp->next = head;
        return;
    }
    temp->next = head;
    head = temp;
    tail->next = head;
}

void insertNodeTail(int data, Node* &tail, Node* &head) {
    Node* temp = new Node(data);
    if(head == NULL) {
        head = temp;
        tail = temp;
        temp->next = head;
        return;
    }
    tail->next = temp;
    tail = temp;
    tail->next = head;
}

void insertNodeMid(int data, Node* &head, Node* &tail, int pos) {
    if(pos == 1) {
        insertNodeHead(data, head, tail);
        return;
    }
    
    Node* temp = new Node(data);
    Node* curr = head;
    int cnt = 1;
    
    while(cnt < pos-1 && curr != tail) {
        curr = curr->next;
        cnt++;
    }
    
    if(curr == tail) {
        insertNodeTail(data, tail, head);
        return;
    }
    
    temp->next = curr->next;
    curr->next = temp;
}

// Delete

void deleteNode(int pos, Node* &head, Node* &tail){
    if(head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* ptrPrev = head;
    if(pos==1){
        Node* temp = head;
        if (head == tail) { 
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;
            tail->next = head; 
        }
        temp->next = NULL;
        delete temp;
        return;
    }

    ptrPrev = head;
    int i = 1;
    while (i < pos - 1 && ptrPrev->next != head) {
        ptrPrev = ptrPrev->next;
        i++;
    }

    if (ptrPrev->next == head || ptrPrev->next == NULL) {
        cout << "Position out of range." << endl;
        return;
    }

    Node* curr = ptrPrev->next; 
    if (curr == tail) { 
        tail = ptrPrev;
        tail->next = head; 
    } else {
        ptrPrev->next = curr->next; 
    }

    curr->next = NULL;
    delete curr;
}


//Print

void print(Node* &head){
    Node* temp = head;
    cout<<"The Linked list be:- ";
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp != head);
    cout<<endl;
}

// Length

int lengthOfLinkedList(Node* &head){
    if(head == NULL){
        return 0;
    }
    Node* ptr = head;
    int i = 0;
    do{
        i++;
        ptr= ptr->next;
    }while(ptr!= head);
    return i;
}

// Reverse 
void reverse(Node*& head, Node* &tail) {
    if(head == NULL || head == tail) {
        return;
    }
    Node* prev = tail;
    Node* curr = head;
    Node* next = NULL;
    
    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while(curr != head);
    
    tail = head;
    head = prev;
}



int main(){

    Node * n1 = new Node(10);
    n1->next = n1;
    Node* head = n1;
    Node* tail = n1;

    print(head);

    insertNodeHead(11,head,tail);
    insertNodeHead(12,head,tail);
    insertNodeHead(13,head,tail);
    insertNodeHead(14,head,tail);
    insertNodeHead(15,head,tail);
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    cout<<"Tail "<<tail->next->data<<endl;

    print(head);

    insertNodeTail(20,tail, head);
    insertNodeTail(21,tail, head);
    insertNodeTail(22,tail, head);
    insertNodeTail(23,tail, head);
    insertNodeTail(24,tail, head);
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    cout<<"Tail "<<tail->next->data<<endl;


    print(head);

    insertNodeMid(100,head, tail, 2);
    insertNodeMid(101,head, tail, 1);

    print(head);

    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    cout<<"Tail "<<tail->next->data<<endl;

    cout<<"\n ========== Delete ==========="<<endl;
    deleteNode(1,head,tail);
    print(head);

    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    cout<<"Tail "<<tail->next->data<<endl;


    deleteNode(2,head,tail);
    print(head);

    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    cout<<"Tail "<<tail->next->data<<endl;


    deleteNode(11,head,tail);
    print(head);

    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    cout<<"Tail "<<tail->next->data<<endl;


    cout<<"Length:- "<<lengthOfLinkedList(head)<<endl;
    reverse(head,tail);
    print(head);

    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    cout<<"Tail "<<tail->next->data<<endl;


    return 0;
}