// ADD two number:-
// 2 -> 3 -> 5
// 4 -> 5
// => 2 -> 8 -> 0

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
            this->next == NULL;
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

Node* reverse(Node* &head){
    Node* new_node = head;
    Node* curr = head;
    Node* ptr = NULL;
    while(new_node != NULL){
        new_node = new_node->next;
        curr->next = ptr;
        ptr = curr;
        curr = new_node;
    }
    return ptr;
}


Node* add(Node* head1, Node* head2){
    print(head1);
    print(head2);
    head1 = reverse(head1);
    head2 = reverse(head2);
    Node* head= new Node(-1);
    Node* ptr = head;
    int carri = 0;
    int sum = 0;
    while(head1 != NULL && head2 != NULL){
        sum = carri + head1->data + head2->data;
        Node* p1 = head1;
        Node* p2 = head2;

        head1=head1->next;
        head2=head2->next;

        p1->next = NULL;
        p2->next = NULL;
        delete p1;
        delete p2;

        Node* temp = new Node(sum%10);
        head->next = temp;
        head = temp;

        carri = sum/10;
    }
    while(head1 != NULL){
        sum = carri + head1->data;

        Node* p1 = head1;
        head1=head1->next;
        p1->next = NULL;
        delete p1;

        Node* temp = new Node(sum%10);
        head->next = temp;
        head = temp;

        carri = sum/10;
    }
    while(head2 != NULL){
        sum = carri + head2->data;

        Node* p2 = head2;
        head2=head2->next;
        p2->next = NULL;
        delete p2;
        
        Node* temp = new Node(sum%10);
        head->next = temp;
        head = temp;

        carri = sum/10;
    }
    while(carri !=0){
        Node* temp = new Node(carri%10);
        head->next = temp;
        head = temp;
        carri = carri/10;
    }
    Node* temp = ptr;
    ptr = reverse(ptr->next);
    temp-> next = NULL;
    delete temp;
    return ptr;
}


int main(){
    Node* head1 = new Node(5);
    Node* n2 = new Node(0);
    Node* n3 = new Node(2);

    head1->next =n2;
    n2->next = n3;


    Node* head2 = new Node(5);
    Node* h2 = new Node(4);
    Node* h3 = new Node(8); 
    Node* h4 = new Node(8);

    head2->next =h2;
    h2->next = h3;
    h3->next = h4;
    
    Node* head = add(head1, head2);

    cout<<"The Sum be :- "<<endl;
    print(head);

    return 0;
}

