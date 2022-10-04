class Solution {
public:
    //recursive
    int solve(vector<int> &coins,int amount){
        //base case
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }
        
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            //agla call marega aur uss coin ko use karega aur amount ghatega.
            int ans = solve(coins,amount - coins[i]);
            if(ans != INT_MAX){
                //why we are using 1+ans because we have to use that coin also on which we are standing.
                mini = min(mini,1+ans);
            }
        }
        return mini;
    }
    
    //recursion + memoization.
    int solve2(vector<int> &coins,int amount,vector<int> &dp){
        //base case
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }
        
        //check if it is not stored earlier
        if(dp[amount] != -1){
            return dp[amount];
        }
        
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            //agla call marega aur uss coin ko use karega aur amount ghatega.
            int ans = solve(coins,amount - coins[i]);
            if(ans != INT_MAX){
                //why we are using 1+ans because we have to use that coin also on which we are standing.
                mini = min(mini,1+ans);
            }
            //store in dp.
            dp[amount] = mini;
        }
        return mini;
    }
    
    //tabulation
    int solveTab(vector<int> &coins,int amount){
        //make dp array.
        //kyunki bottom up me jare hai to INT_MAX se banaya hai .
        vector<int> dp(amount+1,INT_MAX);
        
        //base case
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                
                //check if index is not gone negative
                if((i - coins[j] >= 0) && (dp[i - coins[j]] != INT_MAX))
                 dp[i] = min(dp[i],1+dp[i-coins[j]]);
                 //same relation as done in memoization.
            }
        }
        
        if(dp[amount] == INT_MAX){
            return -1;
        }
        
        return dp[amount];
    }
    
    //uttu soln
//     class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
        
//         vector<int> dp(amount + 1, 1e5);
        
//         dp[0] = 0;
        
//         for(int x = 1; x <= amount; x++) {
//             for(int c : coins) {
//                 if(x - c >= 0) dp[x] = min(dp[x], 1 + dp[x - c]);
//             }
//         }
        
//         if(dp[amount] >= 1e5) return -1;
//         return dp[amount];
        
//     }
// };
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,-1);
        // int ans = solve(coins,amount);
        // if(ans == INT_MAX){
        //     return -1;
        // }
        // return ans;
        
        // int ans = solve2(coins,amount,dp);
        // if(ans == INT_MAX){
        //     return -1;
        // }
        // return ans;
        
        int ans = solveTab(coins,amount);
        return ans;
    }
};