//algo is first use inorder property of bst and store in vector. Now find mid in the vector, and make root of that value ,then pass left of vector to left call of root,and right of vector to root -> right call.
class Solution {
public:
    
    void getInorder(TreeNode* root,vector<int> &in){
        //base case
        if(!root){
            return;
        }
        
        //left call
        getInorder(root -> left,in);
        //add in vector 
        in.push_back(root -> val);
        //right call
        getInorder(root -> right,in);
    }
    
    TreeNode* makeTree(int s,int e,vector<int> &in){
        //base case
        if(s > e){
            return NULL;
        }
        
        //find mid 
        int mid = (s+e)/2;
        //making root of mid value.
        TreeNode* root = new TreeNode(in[mid]);
        
        //left call
        root -> left = makeTree(s,mid-1,in);
        //right call
        root -> right = makeTree(mid+1,e,in);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        getInorder(root,inorder);
        
        //to make tree from inorder
        return makeTree(0,inorder.size()-1,inorder);
    }
};