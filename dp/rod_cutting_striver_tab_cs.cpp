int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    //tabulations
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int notTakeLen = dp[i-1][j];
            int takeLen = INT_MIN;
            if(i <= j){
                takeLen = dp[i][j-i] + price[i-1];
            }
            dp[i][j] = max(takeLen,notTakeLen);
        }
    }
    return dp[n][n];
}
