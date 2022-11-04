#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    
    //base case
    for(int j=0;j<m;j++){
        dp[0][j] = matrix[0][j];
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int down,leftdown,rightdown = -1e8;
            
            down = matrix[i][j] + dp[i-1][j];
            
            if(j-1 >= 0){
                leftdown = matrix[i][j] + dp[i-1][j-1];
            }
            else{
                leftdown += -1e8;
            }
            
            if(j+1 < m){
                rightdown = matrix[i][j] + dp[i-1][j+1];
            }
            else{
                rightdown += -1e8;
            }
            
            dp[i][j] = max(down,max(leftdown,rightdown));
        }
    }
    
    int maxi = dp[n-1][0];
    for(int j=1;j<m;j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    return maxi;
}