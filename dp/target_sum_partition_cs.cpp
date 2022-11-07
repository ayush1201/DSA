//same as target sum but slight change
bool solve(vector<int> &arr,int n,int sum){
    //vector<vector<bool>> dp(n,vector<bool> (sum+1,0));
    vector<bool> cur(sum+1,0),prev(sum+1,0);
    //base cases.
    cur[0] = prev[0] = true;
//     for(int i=0;i<n;i++){
//         dp[i][0] = true;
//     }
    prev[arr[0]] = true;
//     for(int j=0;j<=sum;j++){
//         dp[0][j] = false;
//     }
    
//     dp[0][arr[0]] = true;
    
    for(int i=1;i<n;i++){
        for(int j=1;j<=sum;j++){
            if(i > 0){
                bool nottake = prev[j];
                bool take = false;
                if(j >= arr[i]){
                    take = prev[j-arr[i]];
                }
                cur[j] = take||nottake;
            }
        }
        prev = cur;
    }
    return prev[sum];
}
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    int totsum = 0;
    for(int i=0;i<n;i++){
        totsum += arr[i];
    }
    
    if(totsum%2!=0){
        return false;
    }
    else{
        return (solve(arr,n,totsum/2));
    }
}
