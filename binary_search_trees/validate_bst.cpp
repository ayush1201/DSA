//inorder of bst is always sorted and we can check if it is not sorted then it is not BST.
class Solution {
public:
    
    void inorderTraverse(TreeNode* root,vector<int> &inorder){
        //base case
        if(!root){
            return;
        }
        
        //left call.
        inorderTraverse(root -> left,inorder);
        //store while returning from left
        inorder.push_back(root -> val);
        //right call
        inorderTraverse(root -> right,inorder);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraverse(root,inorder);
        //check if the inorder is sorted.
        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i] >= inorder[i+1]){
                return false;
            }
        }
        return true;
    }
};