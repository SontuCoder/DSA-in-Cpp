// Flatten a Linked list:-

//  5 -> 10 -> 19 -> 28
//  |     |     |       
//  7    11    22     
//  |           |
//  8          50
//  |
//  30

// => 5 -> 7 -> 8 -> 10 -> 11 -> 19 -> 22 -> 28 -> 30 -> 50

// sub list is sorted. (down direction)

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* child;

    Node(int value){
        this->data = value;
        this->next = NULL;
        this->child = NULL;
    }
    ~Node(){
        if(this->child != NULL || this->next != NULL){
            this->child = NULL;
            this->next =NULL;
        }
    }
};


void print(Node* &head){
    Node* ptr = head;
    cout<<"The list be:- \n";
    while(ptr != NULL){
        Node* temp = ptr;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->child;
        } cout<<endl;
        ptr = ptr->next;
    }
    cout<<endl;
}

Node* downToflate(Node* down){
    Node* ptr = new Node(-1);
    Node* head = ptr;
    while(down != NULL){
        ptr->next = down;
        down = down->child;
        ptr = ptr->next;
        ptr->child = NULL;
    }
    ptr = head;
    head = head->next;
    ptr->next = NULL;
    delete ptr;
    return head;
}

Node* margeLL(Node* down, Node* right){
    if(!down) return right;

    if(!right) return downToflate(down);

    Node* ptr = new Node(-1);
    Node* head = ptr;

    while(down != NULL && right != NULL){
        if(down->data < right->data){
            ptr->next = down;
            down = down->child;
        } else {
            ptr->next = right;
            right = right->next;
        }

        ptr = ptr->next;
        if(ptr != NULL){
            ptr->child = NULL;
        }
    }

    while(down != NULL){
        ptr->next = down;
        down = down->child;
        ptr = ptr->next;
        if(ptr != NULL){
            ptr->child = NULL;
        }
    } 
    while(right != NULL){
        ptr->next = right;
        right = right->next;
        ptr = ptr->next;
        if(ptr != NULL){
            ptr->child = NULL;
        }
    }

    ptr = head;
    head = head->next;
    ptr->next = NULL;
    delete ptr;

    return head;
}

Node* sortLL(Node* head){
    if(head == NULL) return head;
    Node* down = head;
    Node* right = head->next;
    head->next = NULL;
    right = sortLL(right);
    return margeLL(down, right);
}

int main(){

    Node* head1 = new Node(5);
    Node* n2 = new Node(10);
    Node* n3 = new Node(19);
    Node* n4 = new Node(28);
    Node* c1 = new Node(7);
    Node* c2 = new Node(8);
    Node* c3 = new Node(30);
    Node* c4 = new Node(11);
    Node* c5 = new Node(22);
    Node* c6 = new Node(50);

    head1->next =n2;
    n2->next = n3;
    n3->next = n4;

    head1->child = c1;
    c1->child = c2;
    c2->child = c3;
    n2->child = c4;
    n3->child = c5;
    c5->child = c6;

    print(head1);
    Node* head = sortLL(head1);
    print(head);
    
    return 0;
}
