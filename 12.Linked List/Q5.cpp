// Remove Loop from LL

#include<iostream>
#include<map>
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

void removeLoop(Node* noob, Node* &pro){
    Node* ptr = pro;
    if(noob == pro) {
        while(ptr->next != noob) {
            ptr = ptr->next;
        }
        ptr->next = NULL;
        return;
    }

    while(ptr->next != noob->next){
        ptr= ptr->next;
        noob= noob->next;
    }
    ptr->next = NULL;
}

void firstNodeLoop(Node* &head){
    if(head == NULL || head->next == NULL) return ;

    Node* pro = head;
    Node* noob = head;
    while(pro != NULL && pro->next != NULL){
        pro= pro->next->next;
        noob= noob->next;
        if(pro == noob){
            removeLoop(head, noob);
            return;
        }
    }
}

void print(Node* &head){
    Node* ptr = head;
    cout<<"The list be:- ";
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}


int main(){

    Node * head = new Node(1);
    Node * n2 = new Node(2);
    Node * n3 = new Node(3);
    Node * n4 = new Node(4);
    Node * n5 = new Node(5);
    Node * n6 = new Node(6);

    head->next =n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n3;

    firstNodeLoop(head);
    print(head);

    return 0;
}