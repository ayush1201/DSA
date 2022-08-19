class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base case if roots null then return true.
        if(!p && !q){
            return true;
        }
        if(!p && q){
            return false;
        }
        if(p && !q){
            return false;
        }
        
        bool left = isSameTree(p -> left,q -> left);
        bool right = isSameTree(p -> right,q -> right);
        bool ans = p->val == q->val;
        
        if(left && right && ans){
            return true;
        }
        else{
            return false;
        }
    }
};