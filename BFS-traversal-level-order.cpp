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
    node* root= new node(data);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}

void bfs(node* root){
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f=q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<f -> data<<" ";
            q.pop();
            if(f->left!=NULL){ //if left node exists, then push it in the queue.
                q.push(f->left);
            }
            if(f->right!=NULL){ //if left node exists, then push it in the queue.
                q.push(f->right);
            }
        }
        
    }
    
    return;
}

int main(){
    node* root=buildtree();
    bfs(root);
    return 0;
}