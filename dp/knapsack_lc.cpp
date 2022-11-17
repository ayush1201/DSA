#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int W) 
{
	// Write your code here
    //tabulation
    vector<vector<int>> dp(n,vector<int> (W+1,0));
    for(int j=0;j<=W;j++){
        //base case.
        if(weight[0] <= j){
            dp[0][j] = value[0];
        }
    }
//     for(int i=0;i<n;i++){
//         dp[i][0] = 0;
//     }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<=W;j++){
            int notpick = dp[i-1][j];
            int pick = INT_MIN;
            if(weight[i] <= j){
                pick = dp[i-1][j-weight[i]] + value[i];
            }
            dp[i][j] = max(pick,notpick);
        }
    }
    return dp[n-1][W];
}