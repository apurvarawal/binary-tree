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

node* buildtree(){
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }
    node* root = new node(data);
    root->left=buildtree();
    root->right=buildtree();
}

void levelorder(node* root){
    queue <node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            q.push(NULL);
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        } 
        
    }
}

//trees with target as the root node
void printAtLevelK(node* root,int k){
    if(root==NULL){
        return;
    }

    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printAtLevelK(root->left,k-1);
    printAtLevelK(root->right,k-1);
    return;
}

//left side and right side of the target node
int printallK(node* root, node* target, int k){

    if(root==NULL){
        return -1;
    }
    if(root==target){
        printAtLevelK(target,k);
        return 0;
    }

    int DL = printallK(root->left, target, k);
    if(DL!=-1){
        //2 cases
        //1. print the ancestor
        if(DL+1==k){
            cout<<root->data<<" ";
        }
        //2. go to the right of the ancestor.
        else{
            printAtLevelK(target,k-DL-2);
        }
        return 1+DL;
    }

    int DR = printallK(root->right, target,k);
    if(DR!=-1){
        if(DR+1==k){
            cout<<root->data<<" ";
        }else{
            printAtLevelK(target,k-DR-2);
        }
        return 1+DR;
    }
    return -1; //node was not present in left or right subtree
} 
int main(){
    node* root=buildtree();
    levelorder(root);
    node* target = root->left->left;
    int k;
    cin>>k;
    printallK(root,target,k);
    return 0;
}