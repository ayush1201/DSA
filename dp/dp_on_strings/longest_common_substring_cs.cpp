#include <bits/stdc++.h>
//same as longest common subsequence just slight change in not matching condition because we are not dependent on previous states as we need consecutive characters to be same.
int lcs(string &str1, string &str2){
	//	Write your code here.
    int n1 = str1.length();
    int n2 = str2.length();
    vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
    int maxLen = 0;
    
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            //matching condition
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                maxLen = max(maxLen,dp[i][j]);
            }
            //not matching condition.
            else{
                dp[i][j] = 0;
            }
        }
    }
    return maxLen;
}