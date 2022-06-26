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

void bfs(node* root){
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
            cout<<f->data<<" ";
            q.pop();
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}

node* buildtreeFromPreAndIn(int *inorder, int *preorder, int s, int e){
    static int i=0;
    if(s>e){
        return NULL;
    }

    node* root = new node(preorder[i]);
    int index = -1;
    for(int j=s; s<=e; j++){
        if(inorder[j]==preorder[i]){
            index=j;
            break;
        }
    }
    i++;
    root->left = buildtreeFromPreAndIn(inorder,preorder,s,index-1);
    root->right= buildtreeFromPreAndIn(inorder,preorder,index+1,e);
    return root;
}
int main(){
    int preorder[]={1,2,3,4,8,5,6,7};
    int inorder[]={3,2,8,4,1,6,7,5};
    int n=7;

    node* root=buildtreeFromPreAndIn(inorder,preorder,0,n-1);
    bfs(root);
    return 0;
}