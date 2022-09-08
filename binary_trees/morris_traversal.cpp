//morris traversal in o(n) and o(1) space.
//algo - first check if root -> left is null then print root -> data and go right. Else find inop(inorder predecessor) which is first left and then right till last node , and inop -> right is null ,make inop ->  right = root and move root left or else if it is not null then print root -> data and unlink inop -> right to NULL and move root right.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        //curr = root.
        while(root){
            if(!(root -> left)){
                ans.push_back(root -> val);
                root = root -> right;
            }
            else{
                //two cases inorder predecessor null or not null and fisrt need to calculate inop.
                TreeNode* inop = root -> left;
                while(inop -> right && inop -> right != root){
                    inop = inop -> right;
                }
                
                if(!(inop -> right)){
                    inop -> right = root;
                    //move root left
                    root = root -> left;
                }
                else{
                    //first of all print the inop 
                    ans.push_back(root -> val);
                    inop -> right = NULL;
                    root = root -> right;
                }
            }
            
        }
        return ans;
    }
};