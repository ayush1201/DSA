class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(!root){
            return NULL;
        }
        //go left if root value is greater than p and q.
        if((root -> val > p -> val) && (root -> val > q -> val)){
            return lowestCommonAncestor(root -> left,p,q);
        }
        //go right if root value is lesser than p and q.
        else if((root -> val < p -> val) && (root -> val < q -> val)){
            return lowestCommonAncestor(root -> right,p,q);
        }
        return root;
    }
};