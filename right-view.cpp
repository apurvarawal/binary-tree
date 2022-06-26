#include<iostream>
#include<queue>
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

void rightview(node* root, int level, int &maxlevel){
    if(root==NULL){
        return;
    }

    if(maxlevel<level){
        cout<<root->data<<" ";
        maxlevel = level;
    }

    rightview(root->right,level+1,maxlevel);
    rightview(root->left,level+1,maxlevel);
}
int main(){
    node* root=NULL;
    cin>>root->data;
    cout<<root->data<<endl;
    int maxlevel = -1;
    rightview(root,0,maxlevel);
    return 0;
}