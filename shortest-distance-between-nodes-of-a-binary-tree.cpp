#include<iostream>
#include<algorithm>
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

node* lca(node* root, int a, int b){
    if(root==NULL){
        return NULL;
    }

    if(root->data==a || root->data==b){
        return root;
    }

    node* leftans=lca(root->left,a,b);
    node* rightans=lca(root->right,a,b);

    if(leftans!=NULL && rightans!=NULL){
        return root;
    }

    if(left!=NULL){
        return leftans;
    }
    return rightans;
}

int search(node* root, int key, int level){
    if(root==NULL){
        return -1;
    }

    if(root->data==key){
        return level;
    }

    int left = search(root->left, key, level+1);

    if(left!=-1){
        return left;
    }
    int right = search(root->right,key,level+1);
    return right;
}

int shortestPath(node* root, int a, int b){
    node* lca_node = lca(root,a,b);

    int l1 = search(lca_node,a,0);
    int l2 = search(lca_node,b,0);

    return abs(l1+l2);

}
int main(){
    node* root = buildtree();
    int a=7, b=4;
    cout<<shortestPath(root,a,b);
    return 0;
}