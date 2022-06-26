#include<iostream>
#include<cstdlib>
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

class height{
    public:
    int Height;
    bool balance;
};

height isbalanced(node* root){
    height p;
    if(root==NULL){
        p.Height=0;
        p.balance=true;
        return p;
    }

    height left = isbalanced(root->left);
    height right = isbalanced(root->right);

    p.Height=max(left.Height,right.Height)+1;

    if(abs(left.Height-p.Height)<=1 && left.balance && right.balance){
        p.balance=true;
    }else{
        p.balance=false;
    }
    return p;
} 
int main(){
    node* root=buildtree();
    if(isbalanced(root).balance==true){
        cout<<"balanced";
    }else{
        cout<<"not balanced";
    }
    return 0;
}