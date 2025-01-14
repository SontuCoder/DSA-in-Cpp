//  Circular Queue :-


#include<iostream>
using namespace std;

class QueueArray {
    int *arr;
    int f;  // Front index
    int r;  // Rear index
    int s;  // Capacity

public:
    // Constructor
    QueueArray(int size) {
        s = size;
        arr = new int[s];
        f = r = -1;
    }

    // Destructor
    ~QueueArray() {
        delete[] arr;
    }

    // Check if the queue is empty
    bool empty() {
        return f == -1;
    }

    // Check if the queue is full
    bool full() {
        return (r + 1) % s == f;
    }

    // Push operation to add an element
    void push(int value) {
        if (full()) {
            cout << "Queue is full. Cannot push " << value << "." << endl;
            return;
        }

        // If queue is empty, set front to 0
        if (f == -1) f = 0;

        r = (r + 1) % s;
        arr[r] = value;
    }

    // Pop operation to remove an element
    void pop() {
        if (empty()) {
            cout << "Queue is empty. Nothing to pop." << endl;
            return;
        }

        if (f == r) {
            f = r = -1;  // Reset queue when empty
        } else {
            f = (f + 1) % s;
        }
    }

    // Get the front element
    int front() {
        if (empty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[f];
    }

    // Get the number of elements in the queue
    int size() {
        if (empty()) return 0;
        if (r >= f) return r - f + 1;
        return s - f + r + 1;
    }

    // Print the elements in the queue
    void print() {
        if (empty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = f;
        while (true) {
            cout << arr[i] << " ";
            if (i == r) break;
            i = (i + 1) % s;
        }
        cout << endl;
    }
};


struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;  
    Node* rear;  

public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        cout << "Enqueuing: " << data << endl;

        if (isEmpty()) {  
            front = rear = newNode;
            rear->next = front;
            return;
        }
        
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to dequeue." << endl;
            return -1;
        }

        Node* temp = front;
        int dequeuedValue = temp->data;

        if (front == rear) {
            rear = nullptr;
        } else {
            front = front->next;
            rear->next = front;
        }
        delete temp;
        cout << "Dequeued: " << dequeuedValue << endl;
        return dequeuedValue;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        do {
            cout << temp->data << " <- ";
            temp = temp->next;
        }while (temp != front);
        cout << "NULL" << endl;
    }

};


int main(){
    // QueueArray q(5);

    // q.push(12);
    // q.push(13);
    // q.push(14);
    // q.push(15);
    // q.push(16);

    // q.print();

    // q.pop();
    // q.print();
    // q.push(18);
    // q.print();
    // cout<<"Size :- "<<q.size();


    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.display();
    return 0;
}