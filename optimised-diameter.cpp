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

class Pair{
    public:
    int height;
    int diameter;
};

Pair greatestDiameter(node* root){
    Pair p;
    if(root==NULL){
        p.height=p.diameter=0;
        return p;
    }

    Pair left = greatestDiameter(root->left);
    Pair right= greatestDiameter(root->right);

    p.height=max(left.height,right.height)+1;
    p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));

    return p;
}

int main(){
    node* root=buildtree();
    Pair p = greatestDiameter(root);
    cout<<p.height<<endl;
    cout<<p.diameter<<endl;
    return 0;
}