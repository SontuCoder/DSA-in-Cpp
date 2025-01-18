// Identical trees or not

#include<iostream>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node *l;
    Node *r;

    Node(int val)
    {
        this->data = val;
        this->l = NULL;
        this->r = NULL;
    }
};

void levelOrder(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(head);
    q.push(NULL);
    while (!q.empty())
    {
        Node *ptr = q.front();
        q.pop();

        if (ptr == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << ptr->data << " ";
            if (ptr->l != NULL)
            {
                q.push(ptr->l);
            }
            if (ptr->r != NULL)
            {
                q.push(ptr->r);
            }
        }
    }
}

Node* createLevelOrder(){
    cout << "Enter value:- ";
    int n;
    cin >> n;
    if (n == -1)
    {
        return NULL;
    }

    Node *node = new Node(n);
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        Node* ptr = q.front();
        q.pop();
        cout << "Enter value left of "<<ptr->data<<" :- ";
        cin >> n;
        if (n != -1)
        {
            ptr->l = new Node(n);
            q.push(ptr->l);
        }
        cout << "Enter value right of "<<ptr->data<<" :- ";
        cin >> n;
        if (n != -1)
        {
            ptr->r = new Node(n);
            q.push(ptr->r);
        }
    }
    return node;
}

// Approach 1
bool identical(Node* head1, Node* head2){
    if((head1 == NULL && head2 != NULL) || (head1 != NULL && head2 == NULL)) return false;
    if(head1 == NULL && head2 == NULL) return true;
    bool left = identical(head1->l, head2->l);
    bool right = identical(head1->r, head2->r);
    return right && left && (head1->data == head2->data);
}


int main(){
    // 1 3 7 -1 -1 -1 -1,
    Node* head1 = createLevelOrder();
    cout<<"\n=============================="<<endl;
    Node* head2 = createLevelOrder();
    cout<<"\n=============================="<<endl;
    levelOrder(head1);
    cout<<"\n=============================="<<endl;
    levelOrder(head2);
    cout<<"Identical :- "<<identical(head1, head2);
    return 0;
}