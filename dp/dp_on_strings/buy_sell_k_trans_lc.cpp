//same as 2 transactions allowed.
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>> (n,vector<int> (k+1,0)));
        //base cases
        for(int j=0;j<n;j++){
            dp[1][j][0] = INT_MIN;
        }
        //this is the only diff bet 2 transaction and k transactiosn that we have to fill all the k transactions boxes .
        for(int tran=1;tran<=k;tran++){
            dp[0][0][tran] = 0;
            dp[1][0][tran] = -prices[0];
            for(int j=1;j<n;j++){
                dp[0][j][tran] = max(dp[0][j-1][tran],dp[1][j-1][tran] + prices[j]);
                dp[1][j][tran] = max(dp[1][j-1][tran],dp[0][j-1][tran-1] - prices[j]);
            }
        }

        return dp[0][n-1][k];

    }
};