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
    if(d == -1) return NULL;
    Node* root = new Node(d);
    root->left = buildBinaryTree();
    root->right = buildBinaryTree();
    return root;
}
void printKNode(Node* root, int d){
    if(root == NULL) return ;
    if(d<0) return;
    if(d == 0){
        cout<<root->data<<" ";
        return ;
    }
    printKNode(root->left, d-1);
    printKNode(root->right, d-1);
    return ;
}
int findTargetNode(Node* root, int target, int d){
    if(root == NULL) return -1;
    if(root->data == target){
        //It means that the target node is found here..
        printKNode(root, d);
        return 0;
    }
    int lhs = findTargetNode(root->left, target, d);
    //if k is not equal to -1..
    //It means that we are returning from the target node to the ancestral node..
    if(lhs!=-1){
        if(d-lhs-1 == 0){
            //It means we are at correct node to be printed...
            cout<<root->data;
        }
        else{
            printKNode(root->right, d-lhs-2);
        }
        return lhs+1;
    }
    int rhs = findTargetNode(root->right, target, d);
    if(rhs!=-1){
        if(d-rhs-1 == 0){
            //It means we are at correct node to be printed...
            cout<<root->data;
        }
        else{
            printKNode(root->right, d-rhs-2);
        }
        return rhs+1;
    }
    return -1;
}
void preorder(Node* root){
    if(root == NULL) return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return ;
}
int main(){
    Node* root = buildBinaryTree();
    //The building of the binary tree is completed here..
    int target, d; cin>>target>>d;
    findTargetNode(root, target, d);
    cout<<endl;
    preorder(root);
    return 0;
}