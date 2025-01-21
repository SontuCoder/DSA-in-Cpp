// Build tree from Inorder and postOrder :-

#include<iostream>
#include<map>
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

void preOrder(Node* head){
    if(head==NULL) return;
    cout<<head->data<<" ";
    preOrder(head->l);
    preOrder(head->r);
}

void createMap(vector<int> in, map<int, int> &nodeIndex){
    for (int i = 0; i < in.size(); i++)
    {
        nodeIndex[in[i]]=i;
    }
}

Node* solve(vector<int> in, vector<int> post, int &index, int inOrderIndex, int inOderEnd, int n, map<int,int> nodeIndexIn){
    if(index < 0 || inOrderIndex> inOderEnd) return NULL;

    int element = post[index--];

    Node* node = new Node(element);
    int position = nodeIndexIn[element];

    node->r = solve(in, post, index, position+1, inOderEnd, n,nodeIndexIn);
    node->l = solve(in, post, index, inOrderIndex, position-1, n,nodeIndexIn);

    return node;
}


Node* buildTree(vector<int> in, vector<int> post){
    int index = post.size()-1;
    map<int, int> nodeIndexIn;
    createMap(in,nodeIndexIn);
    Node* ans = solve(in, post, index, 0, in.size()-1, in.size(),nodeIndexIn);
    return ans;
}


int main(){
    vector<int> in = {3,1,4,0,5,2};
    vector<int> post ={3, 4, 1, 5, 2, 0};
    Node* head = buildTree(in, post);
    cout<<"========================="<<endl;
    preOrder(head); // 0,1,3,4,2,5

    return 0;
}