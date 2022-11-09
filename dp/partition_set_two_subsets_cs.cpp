#include <bits/stdc++.h> 
//same as target sum the catch is that we need to check for every sum possible in last row if it is possible than s2 = target - s1 and s2 - s1 should be minimum.
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int tot = 0;
    for(int i=0;i<n;i++){
        tot += arr[i];
    }
    vector<vector<bool>> dp(n,vector<bool> (tot+1,false));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    
    for(int i=1;i<n;i++){
        for(int j=1;j<=tot;j++){
            bool nottake = dp[i-1][j];
            bool take = false;
            if(arr[i] <= j){
                take = dp[i-1][j-arr[i]];
            }
            dp[i][j] = take|nottake;
        }
    }
    
    int minDiff = INT_MAX;
    for(int j=0;j<=tot;j++){
        if(dp[n-1][j] == true){
            int s1 = j;
            int s2 = tot - j;
            minDiff = min(minDiff,abs(s2 - s1));
        }
    }
    return minDiff;
}
