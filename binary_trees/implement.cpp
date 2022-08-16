#include<iostream>
using namespace std;
#include<queue>

class node{
    public:
     
     int data ;
     node* left;
     node* right;

     node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
     }
};

node* buildTree(node* root){
    cout<<"enter the data :"<<endl;
    int data;
    cin>>data;
    //initiallising root
    root = new node(data);

    //base case
    if(data == -1){
        return NULL;
    }

    cout<<"enter the left child :"<<endl;
    root -> left = buildTree(root -> left);
    cout<<"enter the right child :"<<endl;
    root -> right = buildTree(root -> right);
    return root;
}

void levelOrderTraverse(node* root){
    queue<node*> q;
    q.push(root);
    //NULL will act as seperator and when NULL is reached simply go to next line.
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();

        q.pop();

        if(temp == NULL){
            //purana level khatam hogya hai
            cout<<endl;
            //agar abhi bhi elements baki hai to dobara space dalo
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp -> data<<" ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

void inorderTraverse(node* root){
    //base case (LNR rule)
    if(root == NULL){
        return;
    }

    //recursive call for left
    inorderTraverse(root->left);
    //printing N
    cout<<root -> data<<" ";
    //recursive call for right
    inorderTraverse(root->right);
}

void preOrderTraverse(node* root){
    //base case (NLR rule)
    if(root == NULL){
        return;
    }

    //printing N
    cout<<root -> data<<" ";
    //recursive call for left
    preOrderTraverse(root -> left);
    //recursive call for right
    preOrderTraverse(root -> right);
}

void postOrderTraverse(node* root){
    //base case (LRN rule)
    if(root == NULL){
        return;
    }

    //recursive call for left
    postOrderTraverse(root -> left);
    //recursive call for right
    postOrderTraverse(root -> right);
    //printing N
    cout<<root -> data<<" ";
    
}

void TreeFromLvlOrderTraverse(node* root){
    queue<node*> q;
    cout<<"enter the root data :"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"enter left node for : "<<temp ->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp -> left = new node(leftdata);
            q.push(temp -> left);
        }

        cout<<"enter right node for : "<<temp ->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp -> right = new node(rightdata);
            q.push(temp -> right);
        }

    }
}
int main(){
//1,3,-1,-1,5,-1,-1.
    node* root = NULL;
    TreeFromLvlOrderTraverse(root);
    levelOrderTraverse(root);
    // //building tree
    // root = buildTree(root);
    // //level order traversal
    // cout<<" level order traversal is :"<<endl;
    // levelOrderTraverse(root);
    // //inorder traversal
    // cout<<"in order traversal is :"<<endl;
    // inorderTraverse(root);
    // cout<<endl;
    // //preorder traversal
    // cout<<"pre order traversal is :"<<endl;
    // preOrderTraverse(root);
    // cout<<endl;
    // //postorder traversal
    // cout<<"post order traversal is :"<<endl;
    // postOrderTraverse(root);
    return 0;
}