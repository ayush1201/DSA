//just check at every node that is it p or q and if it is return that , else if root is null return null. Then check for leftAns and rightAns and if both are not null return root,if one is not null return that,else if both null return null.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(!root){
            return NULL;
        }
        if(root == p || root == q){
            return root;
        }
        //making two answers leftans and rightans.
        //calling left 
        TreeNode* leftAns = lowestCommonAncestor(root -> left,p,q);
        //call for right
        TreeNode* rightAns = lowestCommonAncestor(root -> right,p,q);
        
        if(leftAns!=NULL && rightAns!=NULL){
            return root;
        }
        else if(leftAns==NULL && rightAns!=NULL){
            return rightAns;
        }
        else if(leftAns!=NULL && rightAns==NULL){
            return leftAns;
        }
        else{
            return NULL;
        }
    }
};