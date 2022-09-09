class Solution {
public:
    TreeNode* solve(TreeNode* root,int val){
        //base case
        //it means no such node is present.
        if(!root){
            return NULL;
        }
        //means node is found.
        if(root -> val == val){
            return root;

        }
        
        //left call
        if(root -> val > val){
            return searchBST(root -> left,val);
        }
        else{
            return searchBST(root -> right,val);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* nodeFound = solve(root,val);
        return nodeFound;
    }
};