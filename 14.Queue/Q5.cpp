// Circular Queue :-

#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int p;
    int d;

    Node(int p, int d)
    {
        this->p = p;
        this->d = d;
    }
};

int station(queue<Node *> q)
{
    int balance = 0;
    int diff = 0;
    int start = -1;
    int st = 0;
    while (!q.empty())
    {
        balance += (q.front()->p - q.front()->d);
        start++;
        if (balance < 0)
        {
            st = start + 1;
            diff = balance;
            balance = 0;
        }
        q.pop();
    }
    if (diff + balance >= 0)
    {
        return st;
    }
    else
        return -1;
}

int main()
{
    queue<Node *> q;
    Node *s1 = new Node(1, 2);
    Node *s2 = new Node(2, 2);
    Node *s3 = new Node(3, 3);
    Node *s4 = new Node(4, 4);
    q.push(s1);
    q.push(s2);
    q.push(s3);
    q.push(s4);

    cout << "Station:- " << station(q);
    return 0;
}