#include<iostream>
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
    Node* root = new Node(d);
    root->left = buildBinaryTree();
    root->right = buildBinaryTree();
    return root;
}
int replaceNodes(Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return root->data;
    int ls = replaceNodes(root->left);
    int rs = replaceNodes(root->right);
    int temp = root->data;
    root->data = ls+rs;
    return temp + root->data;
}
void print(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
    return ;
}
int main(){
    Node* root = buildBinaryTree();
    replaceNodes(root);
    print(root);
    return 0;
}