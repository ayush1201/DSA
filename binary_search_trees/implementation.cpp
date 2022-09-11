#include<iostream>
#include<queue>
using namespace std;

class Node{

    public:
     int data;
     Node* left = NULL;
     Node* right = NULL;

     Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
     }
};

Node* insertIntoBST(Node* root,int d){
    //base case
    if(root == NULL){
        //matlab initialize karna padega isko 
        root = new Node(d);
        return root;
    }
    
    //if the data entered is big than root data ,go to right node.
    if(d > root -> data){
        root -> right = insertIntoBST(root -> right,d);
    }
    //if data entered is less than root data, go to left.
    else{
        root -> left = insertIntoBST(root -> left ,d);
    }
    return root;
}

Node* levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        if(!temp){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp -> data<<" ";
            if(temp -> left ){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    } 
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    
    //jabtak -1 na enter kia jaye tabtak aage lete raho nodes.
    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

int main(){

    Node* root = NULL;

    cout<<"enter data to create BST "<<endl;
    takeInput(root);
    cout<<" the tree looks like :"<<endl;
    levelOrder(root);

    return 0;
}