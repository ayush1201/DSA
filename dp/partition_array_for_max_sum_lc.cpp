class Solution {
public:
    int solve(int ind,vector<int> &arr,int k,int n,vector<int> &dp){
        //base case 
        if(ind == n)
         return 0;

        if(dp[ind] != -1){
            return dp[ind];
        } 

        int len = 0;
        int maxAns = INT_MIN; 
        int maxi = INT_MIN;
        for(int j=ind;j<min(n,ind+k);j++){
            //exceed na kar jaye j.
            len++;
            maxi = max(maxi,arr[j]);
            int sum = len*maxi + solve(j+1,arr,k,n,dp);
            maxAns = max(maxAns,sum);
        } 
        return dp[ind] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // vector<vector<int>> dp(n,vector<int> (n,0));
        // vector<vector<int>> maxiRec(n,vector<int> (n,0));
        
        // for(int g=0;g<n;g++){
        //     for(int i=0,j=g;j<n;i++,j++){
        //         if(g == 0){
        //             maxiRec[i][j] = arr[i];
        //         }
        //         else{
        //             if(j-i+1 <= k){
        //                 //int maxSum = 0;
        //                 int maxi = 0;
        //                 for(int k=i;k<=j;k++){
        //                     maxi = max(maxi,arr[k]);
        //                 }
        //                 maxiRec[i][j] = maxi*(j-i+1);
        //             }
        //         }
        //     }
        // }

        // for(int g=0;g<n;g++){
        //     for(int i=0,j=g;j<n;i++,j++){
        //         if(g == 0){
        //             //single digit no partition can be done.
        //             dp[i][j] = arr[i];
        //         }
        //         else{
        //             if(j-i+1 <= k){
        //                 int maxSum = 0;
        //                 for(int k=i;k<j;k++){
        //                     maxSum = max(maxSum,dp[i][k] + dp[k+1][j]);
        //                 }
        //                 // int maxi = 0;
        //                 // for(int l=i;l<=j;l++){
        //                 //     maxi = max(maxi,arr[l]);
        //                 // }
        //                 maxSum = max(maxSum,maxiRec[i][j]);
        //                 dp[i][j] = maxSum;
        //             }
        //             else{
        //                 int maxSum = 0;
        //                 for(int k=i;k<j;k++){
        //                     maxSum = max(maxSum,dp[i][k] + dp[k+1][j]);
        //                 }
        //                 dp[i][j] = maxSum;
        //             }
        //         }
        //     }
        // }
        // return dp[0][n-1];


        //recursion wala 
        vector<int> dp(n,-1);
        return solve(0,arr,k,n,dp);

    }
};