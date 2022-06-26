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
    return root;
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

node* lca(node* root, int a, int b){
    if(root==NULL){
        return NULL;
    }
    if(root->data==a || root->data==b){
        //cout<<root->data;
        return root;
    }
    node* leftans = lca(root->left,a,b);
    node* rightans = lca(root->right,a,b);

    if(leftans!=NULL && rightans!=NULL){
        //cout<<root->data;
        return root;
    }
    if(leftans!=NULL){
        return leftans;
    }
    
        return rightans;
    
        
    
}
int main(){
    int a =4 ,b=5;
    node* root=buildtree();
    //levelorder(root);
    cout<<lca(root,a,b)->data;
    return 0;
}