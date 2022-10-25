int mod = (int)(1e9 + 7);
int solve(int i,int j,vector<vector<int>> &mat,vector<vector<int>> &dp){
    //base cases
    if(i == 0 && j == 0){
        return 1;
    }
    if((i < 0 || j < 0) || (mat[i][j] == -1)){
        return 0;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    //up call
    int up = solve(i-1,j,mat,dp);
    //left call
    int left = solve(i,j-1,mat,dp);
    
    dp[i][j] = (((up%mod) + (left%mod))%mod);
    return dp[i][j];
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>> dp(n,vector<int> (m,-1));
    //return solve(n-1,m-1,mat,dp);
    
    //tabulation
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0 && j == 0)dp[i][j] = 1;
            else if(mat[i][j] == -1)dp[i][j] = 0;
            else{
                int up =0;
                int left = 0;
                if(i > 0)up = dp[i-1][j];
                if(j > 0)left = dp[i][j-1];
                dp[i][j] = (left%mod + up%mod)%mod; 
       
            }
        }
    }
    return dp[n-1][m-1];
}