#include <bits/stdc++.h> 

int solve(vector<vector<int>>& t, int n,int i,int j,vector<vector<int>> &dp){
    //base case
    if(i == n-1){
        return t[n-1][j];
    }
    if(j > i){
        return 0;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int down = t[i][j] + solve(t,n,i+1,j,dp);
    int right = t[i][j] + solve(t,n,i+1,j+1,dp);
    
    return dp[i][j] = min(down,right);
}

int minimumPathSum(vector<vector<int>>& t, int n){
	// Write your code here.
    //vector<vector<int>> dp(n,vector<int> (n,-1));
    //return solve(t,n,0,0,dp);
    
    //tabulation
    //reverse of memoization
//     for(int j=0;j<n;j++){
//         dp[n-1][j] = t[n-1][j];
//     }
    
//     for(int i=n-2;i>=0;i--){
//         for(int j=i;j>=0;j--){
//             int down = t[i][j] + dp[i+1][j];
//             int diag = t[i][j] + dp[i+1][j+1];
//             dp[i][j] = min(down,diag);
//         }
//     }
//     return dp[0][0];
    
    //space optimization
    vector<int> curr(n,-1),next(n,-1);
    for(int j=0;j<n;j++){
        next[j] = t[n-1][j];
    }
    
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down = t[i][j] + next[j];
            int diag = t[i][j] + next[j+1];
            curr[j] = min(down,diag);
        }
        next = curr;
    }
    return next[0];
}