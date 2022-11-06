#include <bits/stdc++.h>
bool solve(int index,int target,vector<int> &arr,vector<vector<int>> &dp){
    //base case
    if(index == 0){
        return (arr[0] == target);
    }
    if(target == 0){
        return true;
    }
    
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    
    //relations
    bool nottake = solve(index-1,target,arr,dp);
    bool take = false;
    if(arr[index] <= target){
        take = solve(index-1,target-arr[index],arr,dp);
    }
    return dp[index][target] = (take|nottake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
//     vector<vector<int>> dp(n,vector<int> (k+1,-1));
//     return solve(n-1,k,arr,dp);
    
    //tabulation
    vector<vector<bool>> dp(n+1,vector<bool> (k+1,false));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(i == 0 && j == 0){
                dp[i][j] = true;
            }
            else if(i == 0){
                dp[i][j] = false;
            }
            else if(j == 0){
                dp[i][j] = true;
            }
            else{
                if(dp[i-1][j] == true){
                    //batting nhih karta
                    dp[i][j] = true;
                }
                else{
                    //batting karta hai 
                    int val = arr[i-1];
                    if(val <= j){
                        if(dp[i-1][j-val] == true)
                         dp[i][j] = true;
                    }
                }
            }
     
        }
    }
    
    return dp[n][k];
}