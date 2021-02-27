//Using iterative approach and is a very simple queue based approach..
//Level order printing through recursive approach..
#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int d){
            data = d;
            left = right = NULL;
        }
};
Node* buildBinaryTree(){
    int d; cin>>d;
    if(d == -1){
        return NULL;
    }
    Node* root;
    root = new Node(d);
    root->left = buildBinaryTree();
    root->right = buildBinaryTree();
    return root;
}
void printLevelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* f = q.front();
        q.pop();
        cout<<f->data<<" ";
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
}
int main(){
   Node* root = buildBinaryTree();
   printLevelOrder(root);
   return 0;
}