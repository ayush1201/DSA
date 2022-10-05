class Solution {
public:
    //recursion
//     int solve(vector<int>& nums,int n,vector<int> &dp){
//         //base case
//         if(n < 0){
//             return 0;
//         }
//         if(n == 0){
//             return nums[0];
//         }
        
//         int inclu = solve(nums,n-2) + nums[n];
//         int exclu = solve(nums,n-1) + 0;
//         int maxi = max(inclu,exclu);
//         return maxi;
//     }
    
    //memoization
    int solveMem(vector<int>& nums,int n,vector<int> &dp){
        //base case
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return nums[0];
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        int inclu = solveMem(nums,n-2,dp) + nums[n];
        int exclu = solveMem(nums,n-1,dp) + 0;
        dp[n] = max(inclu,exclu);
        return dp[n];
    }
    
    int rob(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++){
            if(i != n-1){
                v1.push_back(nums[i]);
            }
            if(i != 0){
                v2.push_back(nums[i]);
            }
        }
        int n1 = v1.size();
        int n2 = v2.size();
        int ans1 = solveMem(v1,n1-1,dp);
        //again make dp array back to -1.
        for(auto &i:dp)i = -1;
        int ans2 = solveMem(v2,n2-1,dp);
        int ans = max(ans1,ans2);
        return ans;
    }
};