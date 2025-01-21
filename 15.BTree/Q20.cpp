// Build tree from Inorder and preOrder :-

#include<iostream>
#include<vector>
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

void postOrder(Node* head){
    if(head==NULL) return;
    postOrder(head->l);
    postOrder(head->r);
    cout<<head->data<<" ";
}

int findPosition(vector<int> in, int ele){
    for(int i = 0; i<in.size(); i++){
        if(in[i]==ele){
            return i;
        }
    }
    return -1;
}

Node* solve(vector<int> in, vector<int> pre, int &index, int inOrderIndex, int inOderEnd, int n){
    if(index>= n || inOrderIndex> inOderEnd) return NULL;

    int element = pre[index++];

    Node* node = new Node(element);
    int position = findPosition(in, element);

    node->l = solve(in, pre, index, inOrderIndex, position-1, n);
    node->r = solve(in, pre, index, position+1, inOderEnd, n);

    return node;
}


Node* buildTree(vector<int> in, vector<int> pre){
    int index = 0;
    Node* ans = solve(in, pre, index, 0, in.size()-1, in.size());
    return ans;
}


int main(){
    vector<int> in = {3,1,4,0,5,2};
    vector<int> pre={0,1,3,4,2,5};
    Node* head = buildTree(in, pre);
    cout<<"========================="<<endl;
    postOrder(head); // 3, 4, 1, 5, 2, 0

    return 0;
}