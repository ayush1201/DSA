class Solution {
public:
    
    void solve(vector<vector<int>> &ans,vector<int> res,int index,vector<int>& nums){
        //base case
        if(index>=nums.size()){
            ans.push_back(res);
            return ;
        }
        //exclude element
        solve(ans,res,index+1,nums);
        //include element
        int ele=nums[index];
        res.push_back(ele);
        solve(ans,res,index+1,nums);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        int index=0;
        solve(ans,res,index,nums);
        return ans;
    }
};