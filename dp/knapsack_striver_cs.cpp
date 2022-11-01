#include <bits/stdc++.h> 
int solve(int index,int W,vector<int> &wt,vector<int> &val,vector<vector<int>> &dp){
    //base case
    if(index == 0){
        if(wt[0] <= W){
            return val[0];
        }
        else{
            return 0;
        }
    }
    
    if(dp[index][W] != -1){
        return dp[index][W];
    }
    
    int nottake = 0 + solve(index-1,W,wt,val,dp);
    int take = INT_MIN;
    if(wt[index] <= W){
        take = val[index] + solve(index-1,W-wt[index],wt,val,dp);
    }
    
    dp[index][W] = max(take,nottake);
    return dp[index][W];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
//     vector<vector<int>> dp(n,vector<int> (maxWeight+1,-1));
//     return solve(n-1,maxWeight,weight,value,dp);
    
//     vector<vector<int>> dp(n,vector<int> (maxWeight+1,0));
//     for(int w=weight[0];w<=maxWeight;w++){
//         dp[0][w] = value[0];
//     }
    
//     for(int index=1;index<n;index++){
//         for(int w=0;w<=maxWeight;w++){
//             int nottake = 0 + dp[index-1][w];
//             int take = INT_MIN;
//             if(weight[index] <= w){
//                take = value[index] + dp[index-1][w-weight[index]];
//             }
    
//             dp[index][w] = max(take,nottake);
//         }
//     }
    
//     return dp[n-1][maxWeight];
    
    //space optimized
    vector<int> prev(maxWeight+1,0),curr(maxWeight+1,0);
    //vector<vector<int>> dp(n,vector<int> (maxWeight+1,0));
    for(int w=weight[0];w<=maxWeight;w++){
        prev[w] = value[0];
    }
    
    for(int index=1;index<n;index++){
        for(int w=0;w<=maxWeight;w++){
            int nottake = 0 + prev[w];
            int take = INT_MIN;
            if(weight[index] <= w){
               take = value[index] + prev[w-weight[index]];
            }
    
            curr[w] = max(take,nottake);
        }
        prev = curr;
    }
    
    return prev[maxWeight];
}