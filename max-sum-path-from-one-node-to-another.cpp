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
    node* root=new node(data);
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
}

class Pair{
    public:
    int branchSum;
    int maxSum;

    Pair(){
        branchSum=0;
        maxSum=0;
    }
};

Pair maxSumPath(node* root){
    Pair p;
    if(root==NULL){
        return p;
    }

    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);

    //4 cases if the max sum path passes through root
    int op1 = (left.branchSum)+(right.branchSum)+root->data;
    int op2 = left.branchSum + root->data;
    int op3 = right.branchSum + root->data;
    int op4 = root->data;

    int current_max_sum_passing_from_root = max(op1,max(op2,max(op3,op4)));

    p.branchSum = max(left.branchSum,max(right.branchSum,0))+ root->data;
    p.maxSum = max(left.maxSum,max(right.maxSum,current_max_sum_passing_from_root));

    return p;
}
int main(){
    node* root = buildtree();
    cout<<maxSumPath(root).maxSum;
    return 0;
}