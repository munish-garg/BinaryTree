//Level order printing through recursive approach..
#include<iostream>
#include<cmath>
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
int calculateHeight(Node* root){
    if(root == NULL) return 0;
    int x = calculateHeight(root->left);
    int y = calculateHeight(root->right);
    return max(x,y) + 1;
}
void printLevels(Node* root, int k){
    if(root == NULL) return ;
    if(k == 1){
        //It means we are at the correct level..
        cout<<root->data<<" ";
        return ;
    }
    printLevels(root->left, k-1);
    printLevels(root->right, k-1);
}
int main(){
   Node* root = buildBinaryTree();
   int levels = calculateHeight(root);
   cout<<levels<<endl;
   for(int i=1;i<=levels;i++){
       printLevels(root, i);
       cout<<endl;
   }
    // printLevels(root, 3);
   return 0;
}