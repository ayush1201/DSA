#include <bits/stdc++.h> 
int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n1 = str.length();
    int n2 = ptr.length();
    vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
    
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(str[i-1] == ptr[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int ans = ((n1-dp[n1][n2]) + (n2-dp[n1][n2]));
    return ans;
}