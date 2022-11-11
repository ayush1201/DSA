class Solution {
public:
    int solve(vector<int>& nums, int target,vector<int> &dp){
        //base case
        if(target == 0){
            return 1;
        }
        if(target < 0){
            return 0;
        }
        
        if(dp[target] != -1)
            return dp[target];
        
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += solve(nums,target-nums[i],dp);
            dp[target] = ans;
        }
        return dp[target];
    }
    
    int slveTab(vector<int>& nums, int target){
        vector<int> dp(target+1,0);
        dp[0] = 1;
        
        for(int j=1;j<=target;j++){
            for(int i=0;i<nums.size();i++){
                if(j-nums[i] >= 0){
                    dp[j] += dp[j-nums[i]];
                }
            }
        }
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        // vector<int> dp(target+1,-1);
        // return solve(nums,target,dp);
        return slveTab(nums,target);
    }
};