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
void findTargetNode(Node* root, int target, int k){
    if(root == NULL) return ;
    if(root->data == target){
        //It means that the target node is found here..
        
    }
}
int main(){
    Node* root = buildBinaryTree();
    //The building of the binary tree is completed here..
    int target, k; cin>>target>>k;
    findTargetNode(root, target, k);
    return 0;
}