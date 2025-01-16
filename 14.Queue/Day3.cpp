#include<iostream>
using namespace std;

class Dqueue {
public:
    int* arr;
    int f, r, size;

    // Constructor
    Dqueue(int s) {
        this->size = s;
        arr = new int[s];
        this->f = -1;
        this->r = -1;
    }

    // Push element to the front
    void pushFront(int val) {
        if ((f == 0 && r == size - 1) || (r == (f - 1 + size) % size)) {
            cout << "Queue is full." << endl;
            return;
        } else if (f == -1) { // First element to be inserted
            f = r = 0;
        } else if (f == 0) { // Wrap around the front
            f = size - 1;
        } else {
            f--;
        }
        arr[f] = val;
    }

    // Pop element from the front
    int popFront() {
        if (f == -1) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        int val = arr[f];
        if (f == r) { // Only one element left
            f = r = -1; // Reset queue
        } else if (f == size - 1) {
            f = 0; // Wrap around
        } else {
            f++;
        }
        return val;
    }

    // Push element to the back
    void pushBack(int val) {
        if ((f == 0 && r == size - 1) || (r == (f - 1 + size) % size)) {
            cout << "Queue is full." << endl;
            return;
        } else if (r == -1) { // First element to be inserted
            f = r = 0;
        } else if (r == size - 1) { // Wrap around the back
            r = 0;
        } else {
            r++;
        }
        arr[r] = val;
    }

    // Pop element from the back
    int popBack() {
        if (f == -1) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        int val = arr[r];
        if (f == r) { // Only one element left
            f = r = -1; // Reset queue
        } else if (r == 0) {
            r = size - 1; // Wrap around
        } else {
            r--;
        }
        return val;
    }
};

int main() {
    // Create a deque of size 5
    Dqueue dq(5);

    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushFront(5);
    dq.pushFront(2);

    cout << "Pop Front: " << dq.popFront() << endl; // Should print 2
    cout << "Pop Back: " << dq.popBack() << endl;   // Should print 20

    dq.pushBack(30);
    dq.pushBack(40);

    cout << "Pop Front: " << dq.popFront() << endl; // Should print 5
    cout << "Pop Back: " << dq.popBack() << endl;   // Should print 40

    return 0;
}
