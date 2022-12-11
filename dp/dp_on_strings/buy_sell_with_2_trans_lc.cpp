//three parameters - 1.hold not hold ,2.days record ,3.transaction details.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>> (n,vector<int> (3,0)));
        for(int j=0;j<n;j++){
            //no buying at 0 transaction so INT_MIN profit.
            dp[1][j][0] = INT_MIN;
        }
        //base cases.
        dp[1][0][1] = -prices[0];
        dp[1][0][2] = -prices[0];

        for(int j=1;j<n;j++){
            //the catch is that simply while buying we will consider it as one transaction and check in the previous transaction array while buying that day stock.
            dp[0][j][1] = max(dp[0][j-1][1],dp[1][j-1][1] + prices[j]);
            dp[0][j][2] = max(dp[0][j-1][2],dp[1][j-1][2] + prices[j]);
            dp[1][j][1] = max(dp[1][j-1][1],dp[0][j-1][0] - prices[j]);
            dp[1][j][2] = max(dp[1][j-1][2],dp[0][j-1][1] - prices[j]);
        }
        return dp[0][n-1][2];
    }
};