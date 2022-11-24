class Solution {
public:
    int solve(int i,int j,string &w1,string &w2,int n,int m,vector<vector<int>> &dp){
        //base case
        if(i < 0){
            return j+1;
        }
        if(j < 0){
            return i+1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        //recursion calls.
        if(w1[i] == w2[j]){
            //no need to prform any operations.
            dp[i][j] = 0 + solve(i-1,j-1,w1,w2,n,m,dp);
        }
        else{
            //three operations possible - insertions,deletions,or replacing.
            dp[i][j] = 1 + min(solve(i,j-1,w1,w2,n,m,dp),min(solve(i-1,j,w1,w2,n,m,dp),solve(i-1,j-1,w1,w2,n,m,dp)));
        }
        return dp[i][j];
    }
    
    int minDistance(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        // return solve(n-1,m-1,word1,word2,n,m,dp);
        
        
        //tabulation
        
        //base cases
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            dp[i][0] = i;
        }
        for(int j=1;j<=m;j++){
            dp[0][j] = j;
        }
        
        //calls filling the table
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(w1[i-1] == w2[j-1]){
                    //macthing
                    //do nothing just copy from i-1,j-1
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};