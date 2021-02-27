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
    //What we did using this function is that we build the root node, then we call on the left side..
    //We call on the right side and then the root node formed is returned to the function which called it..
    int d; cin>>d;
    if(d == -1) return NULL;
    Node* root = new Node(d);
    root->left = buildBinaryTree();
    root->right = buildBinaryTree();
    return root;    
}
void preorder(Node* root){
    if(root == NULL) return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}
void postorder(Node* root){
    if(root == NULL) return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return;
}
void inorder(Node* root){
    if(root == NULL) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}
int main(){
    Node* root = buildBinaryTree();
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
    return 0;
}