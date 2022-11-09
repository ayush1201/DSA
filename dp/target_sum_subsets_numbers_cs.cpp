#include <bits/stdc++.h> 
int solve(int index,vector<int> &num, int tar,vector<vector<int>> &dp){
    //base case
    if(tar == 0){
        return 1;
    }
    if(index == 0){
        return num[0] == tar;
    }
    
    if(dp[index][tar] != -1){
        return dp[index][tar];
    }
    
    int nottake = solve(index-1,num,tar,dp);
    int take = 0;
    if(num[index] <= tar){
        take = solve(index-1,num,tar-num[index],dp);
    }
    dp[index][tar] = take + nottake;
    return dp[index][tar];
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n,vector<int> (tar+1,-1));
//     for(int i=0;i<n;i++){
//         dp[i][0] = true;
//     }
//     if(num[0] <= tar)dp[0][num[0]] = true;
    
//     for(int i=1;i<n;i++){
//         for(int j=1;j<=tar;j++){
//             int nottake = dp[i-1][j];
//             int take = 0;
//             if(num[i] <= j){
//                 take = dp[i-1][j-num[i]];
//             }
//             dp[i][j] = take + nottake;
//         }
//     }
//     return dp[n-1][tar];
    return solve(n-1,num,tar,dp);
}