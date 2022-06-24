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

int count(node* root){
    if(root==NULL){
        return 0;
    }
    return 1+count(root->left)+count(root->right);
}

int sum(node* root){
    if(root==NULL){
        return 0;
    }
    return (root->data)+sum(root->left)+sum(root->right);
}
int main(){
    node* root= buildtree();
    cout<<count(root)<<endl;
    cout<<sum(root)<<endl;
    return 0;
}