//normal inorder traversal without morris concept .
class Solution {
public:
    int res;
    
    void solve(TreeNode* root,int &k){
        //base case
        if(!root){
            return;
        }
        
        //left call
        solve(root -> left,k);
        //processing 
        --k;
        if(k == 0){
            res = root -> val;
        }
        //right call
        solve(root -> right,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        solve(root,k);
        return res;
    }
};

//inorder traversal using morris traversal.
