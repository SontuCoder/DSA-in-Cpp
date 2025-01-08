// Implimentation of Stack :-

#include<iostream>
using namespace std;

class StackArray{
    public:
    int top;
    int *arr;
    int size;

    StackArray(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    ~StackArray() {
        delete[] arr;
    }

    bool empty(){
        return (top == -1);
    }

    void pop(){
        if(top == -1){
            cout<<"Stack is empty."<<endl;
            return;
        }
        top--;
    }

    int peek(){
        if(top == -1){
            cout<<"Stack is empty."<<endl;
            return -1;
        }
        return arr[top];
    }

    void push(int value){
        if(top == size-1){
            cout<<"Stack is overflow."<<endl;
            return;
        }
        top++;
        arr[top] = value;
    }


    bool full(){
        return top == (size -1);
    }

    int currentSize() {
        return top + 1;
    }
};

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        if(this->next != NULL){
            this->next = NULL;
        }
    }
    
};


class StackLL{
    public:
    Node* head;
    Node* tail;

    StackLL() {
        head = NULL;
        tail = NULL;
    }

    ~StackLL() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool empty(){
        return head == NULL;
    }

    void pop(){
        if(head == NULL){
            cout<<"Stack is empty."<<endl;
            return;
        }
        if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    int peek(){
        if(head == NULL){
            cout<<"Stack is empty."<<endl;
            return -1;
        }
        return tail->data;
    }

    void push(int value){
        Node* temp = new Node(value);
        if(head == NULL){
            head = tail = temp;
            return;
        }
        tail->next = temp;
        tail = tail->next;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main(){
    // Implement y array :-

    // StackArray st(5);
    // cout<<"pop:- ";
    // st.pop();
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // cout<<"top:-"<<st.peek()<<endl;
    // st.push(4);
    // st.push(5);
    // cout<<"Push in full stack :- ";
    // st.push(6);

    // cout<<"top:-"<<st.peek()<<endl;
    // cout<<"is Empty "<<st.empty()<<endl;
    
    // cout<<"Before pop:- "<<st.full()<<endl;
    // st.pop();
    // cout<<"After pop:-  "<<st.full()<<endl;
    
    // Stack using Linked List
    StackLL stackLL;
    stackLL.pop();
    stackLL.push(10);
    stackLL.push(20);
    stackLL.push(30);
    cout << "Top (Linked List): " << stackLL.peek() << endl;
    cout << "Size (Linked List): " << stackLL.size() << endl;
    stackLL.pop();
    cout << "After pop, top: " << stackLL.peek() << endl;
    cout << "Is Empty (Linked List): " << stackLL.empty() << endl;

    return 0;
}