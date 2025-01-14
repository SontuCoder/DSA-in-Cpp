// Implement Queue By Array and Linked list :-

// Oparations :-
// pop(); push(); front(); size(); empty();

#include <iostream>
using namespace std;

// By array :-
class QueueArray {
    int *arr;
    int f;
    int r;
    int s;

public:
    // Constructor
    QueueArray(int size) {
        this->s = size;
        arr = new int[s];
        f = r = -1;
    }

    // Destructor
    ~QueueArray() {
        delete[] arr;
    }

    // Check if the queue is empty
    bool empty() {
        return (f == -1);
    }

    // Check if the queue is full
    bool full() {
        return (r == s - 1);
    }

    // Push operation to add an element
    void push(int value) {
        if (full()) {
            cout << "Queue is full. Cannot push " << value << "." << endl;
            return;
        }

        if (f == -1) f = 0;  // Set front if queue was empty

        r++;
        arr[r] = value;
    }

    // Pop operation to remove an element
    void pop() {
        if (empty()) {
            cout << "Queue is empty. Nothing to pop." << endl;
            return;
        }

        f++;
        if (f > r) {
            f = r = -1;  // Reset queue if it becomes empty
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

    // Get the current size of the queue
    int size() {
        if (empty()) return 0;
        return r - f + 1;
    }

    // Print the elements in the queue
    void print() {
        if (empty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Elements: ";
        for (int i = f; i <= r; i++) {
            cout << arr[i] << " ";
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

        if (rear == nullptr) {  
            front = rear = newNode;
            return;
        }
        
        rear->next = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to dequeue." << endl;
            return -1;
        }

        Node* temp = front;
        int dequeuedValue = temp->data;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
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
        while (temp != nullptr) {
            cout << temp->data << " <- ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};


int main()
{

    QueueArray q(5);

    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);

    q.print();

    q.pop();
    q.print();
    q.push(18);
    q.print();
    cout<<"Size :- "<<q.size();

    // Queue q;

    // q.enqueue(10);
    // q.enqueue(20);
    // q.enqueue(30);
    // q.display();

    // q.dequeue();
    // q.display();

    return 0;
}