class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(100,vector<double> (100,0));
        // double curr = (double)poured;
        // double currKeBad = 0;
        dp[0][0] = (double)poured;
        for(int i=0;i<100;i++){
            for(int j=0;j<=i;j++){
                if(dp[i][j] >= (double)1){
                    double ans = dp[i][j] - 1;
                    ans = ans/2;
                    dp[i][j] = 1;
                    if (i+1 <= 99)dp[i+1][j] = dp[i+1][j] + ans;
                    if (i+1 <= 99 && j+1 <= 99)dp[i+1][j+1] = dp[i+1][j+1] + ans;
                }
                
            }
        }
        return dp[query_row][query_glass];
    }
};