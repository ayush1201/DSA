 //concept hai ki k levels down bhi use karo aur node to root path bhi use karo aur blocker concept ko use karo in k levels down me.
class Solution {
public:
//hume k levels down ke liye blocker node ka use karna padega jisse barbaar print na ho jaye.
    void kLevelsDown(TreeNode* root,int k,vector<int> &ans,TreeNode* blocker){
        if(!root || k < 0 || (root == blocker)){
            return;
        }
        if(k == 0){
            ans.push_back(root -> val);
            return;
        }

        kLevelsDown(root -> left,k-1,ans,blocker);
        kLevelsDown(root -> right,k-1,ans,blocker);
        return;
    }

    //ye zaruri hai batane ke liye target node se root node tak ke nodes jisse k-i distance ke print kara sake..
    bool nodeToRoot(TreeNode* root,vector<TreeNode*> &track,TreeNode* target){
        if(!root){
            return false;
        }
        bool khud = (root -> val == target -> val);
        if(khud){
            track.push_back(root);
            return true;
        }
        bool left = nodeToRoot(root -> left,track,target);
        if(left){
            track.push_back(root);
            return true;
        }
        bool right = nodeToRoot(root -> right,track,target);
        if(right){
            track.push_back(root);
            return true;
        }
        return false;
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        vector<TreeNode*> track;
        nodeToRoot(root,track,target);
        for(int i=0;i<track.size();i++){
            TreeNode* blocker = new TreeNode();
            //pichla node blocker ban jata hai proper visualise karo.
            kLevelsDown(track[i],k-i,ans,i==0?NULL:track[i-1]);
        }
        return ans;
    }
};