//the concept is simply same to level order traversal ,only thing is just check the condition if it is leftto right or right to left. 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        vector<int> res;
        
        //checking for null condition.
        if(root == NULL){
            return ans;
        }
        
        //for checking the order leftToRight.
        bool leftToRight = true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){

            TreeNode* temp = q.front();
            q.pop();
            
            if(temp == NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                //in the initial order from left to right.
                if(leftToRight){
                    ans.push_back(res);
                    res.clear();
                }
                //in the reverse order from right to left.
                if(!leftToRight){
                    reverse(res.begin(),res.end());
                    ans.push_back(res);
                    res.clear();
                }
                leftToRight = !leftToRight;
            }
            else{
                res.push_back(temp -> val);
                if(temp -> left){
                q.push(temp -> left);
                }
                if(temp -> right){
                q.push(temp -> right);
                }
            }
            
        }
        return ans;
    }
};