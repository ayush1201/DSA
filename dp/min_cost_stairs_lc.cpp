class Solution {
public:
    //recursion + memoization.
    int solve(int index,vector<int> &cost,vector<int> &dp){
        //base case
        if(index == cost.size()-1){
            return cost[cost.size()-1];
        }
        if(index > cost.size()-1){
            return 0;
        }
        
        //step3
        if(dp[index] != -1){
            return dp[index];
        }
        
        //step2
        int case1 = cost[index] + solve(index+1,cost,dp);
        int case2 = cost[index] + solve(index+2,cost,dp);
        return dp[index] = min(case1,case2);
        
    }
    
    //tabulation 
    int solve2(vector<int> &cost,int n){
        //step1
        vector<int> dp(n+1);
        //step2
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        //step3 - dp relation for rest of calls.
        for(int i=2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        
        return min(dp[n-1],dp[n-2]);
    }
    
    //space optimization
    int solve3(vector<int> &cost,int n){
        int prev2 = cost[0];
        int prev1 = cost[1];
        
        //for rest calls.
        for(int i=2;i<n;i++){
            int curr = cost[i] + min(prev1,prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1,prev2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        //step1
        int n = cost.size();
        vector<int> dp(n+1,-1);
        //return min(solve(0,cost,dp),solve(1,cost,dp));
        return solve3(cost,n);
    }
};