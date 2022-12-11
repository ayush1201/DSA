class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2,vector<int> (n,0));
        dp[0][0] = 0;
        dp[1][0] = -prices[0];

        for(int i=1;i<n;i++){
            dp[0][i] = max(dp[0][i-1],dp[1][i-1] + prices[i]);
            if(i-2 >= 0) //just modification here when buying the stock we have to check for day before yesterday profit as we are not allowed to buy just after selling the previous stock.
             dp[1][i] = max(dp[1][i-1],dp[0][i-2] - prices[i]);
            else
             dp[1][i] = max(dp[1][i-1],dp[0][i-1] - prices[i]); 
        }
        return dp[0][n-1];
    }
};