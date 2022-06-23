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
    node* root=new node(data);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}

void print(node* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    print(root->right);
    cout<<root->data<<" ";
}
int main(){
    node* root=buildtree();
    print(root);
    return 0;
}