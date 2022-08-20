//concept is make three function traverse left boundary excluding leaf nodes ,then make leaf boundary function and third will be right boundary traversal without adding leaf nodes.
class Solution {
public:

    void leftTraverse(Node* root,vector<int> &res){
        //base case
        if((!root) || (root -> left == NULL && root -> right == NULL)){
            return;
        }
        
        res.push_back(root -> data);
        if(root -> left){
            leftTraverse(root -> left,res);
        }
        else{
            leftTraverse(root -> right,res);
        }
    }
    
    void leafTraverse(Node* root,vector<int> &res){
        //base case
        if(!root){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            res.push_back(root -> data);
            return;
        }
        leafTraverse(root -> left,res);
        leafTraverse(root -> right,res);
        
    }
    
    void rightTraverse(Node* root,vector<int> &res){
        //base case
        if((!root) || (root -> left == NULL && root -> right == NULL)){
            return ;
        }
        

        if(root -> right){
            rightTraverse(root -> right,res);
        }
        else{
            rightTraverse(root -> left,res);
        }
        
        //post order print karna hai na
        res.push_back(root -> data);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        //base case
        vector<int> res;
        if((!root)){
            return res;
        }
        res.push_back(root -> data);
        //left traversal and printing left boundary excluding leaf.
        leftTraverse(root -> left,res);
        
        //now leaf traversal function.
        //left subtree
        leafTraverse(root -> left,res);
        //right subtree
        leafTraverse(root -> right,res);
        
        //right traversal and print right boundary
        rightTraverse(root -> right,res);
        
        return res;
    }