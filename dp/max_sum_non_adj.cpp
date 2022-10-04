#include <bits/stdc++.h>
//recursion
int solve(vector<int> &nums,int n){
    //base case
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return nums[0];
    }
    
    int incl = solve(nums,n-2) + nums[n];
    int excl = solve(nums,n-1) + 0;
    
    return max(incl,excl);
}
//memoization
int solveMem(vector<int> &nums,int n,vector<int> &dp){
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
    
    int incl = solve(nums,n-2) + nums[n];
    int excl = solve(nums,n-1) + 0;
    
    return dp[n] = max(incl,excl);
}

int solveTab(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,0);
    dp[0] = nums[0];
    for(int i=1;i<n;i++){
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;
        dp[i] = max(incl,excl);
    }
    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    //right to left jayenge.
//     int n = nums.size();
//     int ans = solve(nums,n-1);
//     return ans;
    
//     int n = nums.size();
//     vector<int> dp(n,-1);
//     int ans = solveMem(nums,n-1,dp);
//     return ans;
    return solveTab(nums);
}