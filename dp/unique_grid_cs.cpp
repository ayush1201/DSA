#include <bits/stdc++.h> 
int solveMem(int i,int j,vector<vector<int>> &dp){
    if(i == 0 && j == 0){
        //matlab ye ek tareeka hai 0 tak pahuchne ka
        return 1;
    }
    if(i < 0 || j < 0){
        //koi tareeka nhi hai.
        return 0;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int up = solveMem(i-1,j,dp);
    int left = solveMem(i,j-1,dp);
    dp[i][j] = up + left;
    return dp[i][j];
}

int solveTab(int rows,int cols,vector<vector<int>> &dp){
    //base case
    dp[0][0] = 1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int up = 0;
            int left = 0;
            if(i == 0 && j == 0){
                dp[i][j] = 1;
            }
            else{
                if(i > 0)up = dp[i-1][j];
                if(j > 0)left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[rows-1][cols-1];
}
int uniquePaths(int m, int n) {
	// Write your code here.
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return solveTab(m,n,dp);
}