#include <bits/stdc++.h> 
#define MOD 1000000007
int numberOfWays(int n, int k) {
    // Write your code here.
    //tabulation
    vector<vector<int>> dp(3,(vector<int> (n+1,1)));
    dp[0][2] = k%MOD;
    dp[1][2] = k*(k-1)%MOD;
    dp[2][2] = (dp[0][2] + dp[1][2])%MOD;
    
    for(int i=3;i<=n;i++){
        dp[0][i] = dp[1][i-1]*1;
        dp[1][i] = (dp[2][i-1]*((k-1)%MOD))%MOD;
        dp[2][i] = (dp[0][i] + dp[1][i])%MOD;
    }
    return dp[2][n];
} 
