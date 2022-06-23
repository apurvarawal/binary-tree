//WORST TIME COMPLEXITY : O(N^2)

#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

node* buildtree(){
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }
    node* root= new node(data);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}

void printKthLevel(node* root, int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right,k-1);
    return;
}

int height(node* root){
    if(root==NULL){
        return 0;
    }
    int leftHeight= height(root->left); 
    int rightHeight =height(root->right);
    return max(leftHeight,rightHeight)+1;
}

void printAllLevels(node* root){
    int H = height(root);
    for(int i=0; i<H; i++){
        printKthLevel(root,i);
        cout<<endl;
    }
}

int main(){
    node* root=buildtree();
    printKthLevel(root,3);
    printAllLevels(root);
    cout<<endl<<height(root)<<" ";
    return 0;
}