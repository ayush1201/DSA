#include <bits/stdc++.h> 
//gap strategy method and by cut applying in gaps as k.
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N-1,vector<int> (N-1,-1));
    for(int gap=0;gap<N;gap++){
        for(int i=0,j=gap;j<N-1;i++,j++){
            if(gap == 0){
                dp[i][j] = 0;
            }
            else if(gap == 1){
                dp[i][j] = arr[i] * arr[j] * arr[j+1];
            }
            else{
                int mini = INT_MAX;
                //kat maaro aur partition karo matrices me.
                //left half -> i-k aur right half -> k+1-j.
                for(int k=i;k<j;k++){
                    int left = dp[i][k];
                    int right = dp[k+1][j];
                    int m = arr[i] * arr[k+1] * arr[j+1];
                    mini = min(mini,left+right+m);
                }
                dp[i][j] = mini;
            }
        }
        
    }
    return dp[0][N-2];
}