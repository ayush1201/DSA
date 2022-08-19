class Solution {
public:
    
    pair<bool,int> balanceHaiKya(TreeNode* root){
        //base case
        if(!root){
            return {true,0};
        }
        //apne aap balance hai ya nhi aur uss node tak ki height lake daldega.
        auto[leftkyaBalance,leftHeight] = balanceHaiKya(root -> left);
        auto[rightkyaBalance,rightHeight] = balanceHaiKya(root -> right);
        
        bool balance = leftkyaBalance && rightkyaBalance;
        bool kyaHeightSahiHai = abs(leftHeight - rightHeight) <= 1;
        
        //yaha khud root check karega ki vo balance hai aur uske neeche ki nodes ki height bhi return karega.
        return{balance && kyaHeightSahiHai,max(leftHeight,rightHeight) + 1};
        
    }
    
    bool isBalanced(TreeNode* root) {
        auto[Balanced,Height] = balanceHaiKya(root);
        return Balanced;
    }
};