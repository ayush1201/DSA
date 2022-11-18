//express everything in terms of index and explore all possibilities.
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        //base cases
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        // for(int j=0;j<=amount;j++){
        //     if(j >= coins[0]){
        //         dp[0][j] = 1;
        //     }
        // }
        
        for(int i=0;i<n;i++){
            for(int j=1;j<=amount;j++){
                int nottake = 0;
                if(i > 0){
                    nottake = dp[i-1][j];
                }

                int take = 0;
                if(coins[i] <= j){
                    take = dp[i][j-coins[i]]; //the only catch is that we can choose as many as particular coins so don't go back to previous index.
                }
                dp[i][j] = take + nottake;
            }
        }
        return dp[n-1][amount];
    }
};