#include <bits/stdc++.h> 
int mod  = (int)(1e9+7);
int solve(int index,vector<int> &arr,int tar){
    //base case
    if(index == 0){
        if(arr[index] == 0 && tar == 0){
            return 2;
        }
        if(arr[index] == tar || tar == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    int notpick = solve(index-1,arr,tar);
    int pick = 0;
    if(tar-arr[index] >= 0 ){
        pick = solve(index-1,arr,tar-arr[index]);
    }
    return (pick + notpick)%mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int tot = 0;
    for(int i=0;i<n;i++){
        tot += arr[i];
    }
    //edge cases.
//     if((tot-d)%2==0){
//         int tar = (tot-d)/2;
//         return solve(n-1,arr,tar);
//     }
    
    //tabulation
    if(((tot-d)%2==0) && (tot-d>=0)){
        int tar = (tot-d)/2;
        vector<vector<int>> dp(n,vector<int> (tar+1,0));
        for(int i=0;i<=tar;i++){
            //base cases
            if(arr[0] == 0 && i == 0){
                dp[0][0] = 2;
            }
            else if(arr[0] == i || i == 0){
                dp[0][i] = 1;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=tar;j++){
                int nottake = dp[i-1][j];
                int take = 0;
                if(arr[i] <= j){
                    take = dp[i-1][j-arr[i]];
                }
                dp[i][j] = take + nottake;
            }
        }
        return dp[n-1][tar];
    }
    return 0;
}


