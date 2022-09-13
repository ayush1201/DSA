//use inorder property of bst.
//and then use 2 pointer.
class Solution {
public:
    
    void solve(TreeNode* root,int k,vector<int> &sumArray){
        //simple inorder traversal.
        if(!root){
            return ;
        }
        
        //left call
        solve(root -> left,k,sumArray);
        //append in array
        sumArray.push_back(root -> val);
        //right call.
        solve(root -> right,k,sumArray);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> sumArray;
        solve(root,k,sumArray);
        //check in the array if sum is available.
        int start = 0;
        int end = sumArray.size()-1;
        while(start<end){
            if(sumArray[start] + sumArray[end] == k){
                return true;
            }
            else if(sumArray[start] + sumArray[end] < k){
                start++;
            }
            else{
                end--;
            }
        }
        return false;
    }
};