class Solution {
public:
    
    void solve(vector<int> &candidates,int target,vector<vector<int>> &ans,vector<int> res,int index){
        //base case
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(res);
            }
            //both if target becomes less than given element or if it becomes equal.
            return;
        }
        
        
        
        //if it takes or picks then it has two options again pick the same element or don't pick that element and go to next index.
        if(candidates[index]<=target){
            res.push_back(candidates[index]);
            //recursive call
            solve(candidates,target-candidates[index],ans,res,index);
        
            //after executing all the recursion calls for above picking conditions.
            res.pop_back();//for removing last added element.
        }
        
        //recursive call for not picking
        solve(candidates,target,ans,res,index+1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        solve(candidates,target,ans,res,0);
        return ans;
    }
};