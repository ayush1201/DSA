class Solution {
public:
    void flatten(TreeNode* root) {
        //code here
        TreeNode *curr = root;
        while(curr){
            if(curr -> left){
                TreeNode *inop = curr -> left;
                
                while(inop -> right){
                    inop = inop -> right;
                }
                
                inop -> right = curr -> right;
                curr -> right = curr -> left;
            }
            curr = curr -> right;
        }
        //we have to make left of every node null.
        curr = root;
        while(curr){
            curr -> left = NULL;
            curr = curr -> right;
        }
    }
};