//Only difference is that we have infinite weight of particular values.
#include <bits/stdc++.h> 
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int> (w+1,0));
    for(int i=0;i<n;i++){
        dp[i][0] = 0;
    }
    
    for(int i=0;i<n;i++){
        for(int j=1;j<=w;j++){
            int nottake = 0;
            if(i > 0){
                nottake = dp[i-1][j];
            }
            int take = 0;
            if(weight[i] <= j){
                take = dp[i][j-weight[i]] + profit[i]; //the catch is that we can pick any number of times.
            }
            dp[i][j] = max(take,nottake);
        }
    }
    return dp[n-1][w];
}
