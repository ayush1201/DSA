#include <bits/stdc++.h> 
int solveMem(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
    //base case
    if(i == 0 && j == 0){
        return grid[i][j];
    }
    if(i < 0 || j < 0){
        return INT_MAX;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int up = grid[i][j] + solveMem(i-1,j,grid,dp);
    int left = grid[i][j] + solveMem(i,j-1,grid,dp);
    
    dp[i][j] = min(up,left);
    return dp[i][j];
    
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    //return solveMem(n-1,m-1,grid,dp);
    
    //tabulation
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0 && j == 0)dp[i][j] = grid[i][j];
            else{
                int up = grid[i][j];
                if(i > 0)up += dp[i-1][j];
                else up += 1e9 + 7;
                
                int left = grid[i][j];
                if(j > 0)left += dp[i][j-1];
                else left += 1e9 + 7;
                dp[i][j] = min(left,up);
            }
        }
    }
    return dp[n-1][m-1];
}