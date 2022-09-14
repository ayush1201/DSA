//algo is just take every element in array and create node of that element and just check that it lies within interval  or not.
class Solution {
public:
    
    TreeNode* solve(vector<int>& preorder,int mini,int maxi,int &index){
        //base case
        if(index >= preorder.size()){
            return NULL;
        }
        if(preorder[index] < mini || preorder[index] > maxi){
            return NULL;
        }
        
        //initialize new root 
        TreeNode* root = new TreeNode(preorder[index++]);
        //left call.
        root -> left = solve(preorder,mini,root -> val,index);
        //right call
        root -> right = solve(preorder,root -> val,maxi,index);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int maxi = INT_MAX;
        int mini = INT_MIN;
        int index = 0;
        return solve(preorder,mini,maxi,index);
    }
};