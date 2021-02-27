#include <iostream>
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
void print(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
    return; 
}
int main(){
    Node* root = buildBinaryTree();
    print(root);
    return 0;
}