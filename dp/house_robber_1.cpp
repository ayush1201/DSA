//same as adjacent problem on code studio.
class Solution {
public:
    //recursion.
    int solve(vector<int> &nums,int n){
        //base case
        if(n < 0){
            return 0;  
        }
        if(n == 0){
            return nums[0];
        }
        
        int incl = solve(nums,n-2) + nums[n];
        int excl = solve(nums,n-1);
        
        int maxi = max(incl,excl);
        return maxi;
        
    }
    
    //memoization
    int solveMem(vector<int>& nums,int n,vector<int>& dp){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return nums[0];
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        int incl = solveMem(nums,n-2,dp) + nums[n];
        int excl = solveMem(nums,n-1,dp);
        
        dp[n] = max(incl,excl);
        return dp[n];
    }
    
    //uttu soln
//     class Solution {
// public:
    
//     int rob(vector<int>& a) {
//         int n = a.size();
//         vector<int> dp(n, 0);
//         dp[0] = a[0];
        
        
//         for(int i = 1; i < n; i++) {
//             int include = a[i] + (i - 2 >= 0 ? dp[i - 2] : 0);
//             int exclude = dp[i - 1];
//             dp[i] = max(include, exclude);
//         }
        
//         return dp[n - 1];
        
//     }
// };
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        //return solve(nums,n-1);
        return solveMem(nums,n-1,dp);
    }
};