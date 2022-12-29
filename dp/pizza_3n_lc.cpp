//same as house robber 2 variant just do it for n/3 slices .
class Solution {
public:
    int solve(int ind,int endInd,vector<int>& slices,int n,vector<vector<int>> &dp){
        //base cases
        if(n == 0 || ind > endInd){
            return 0;
        }

        if(dp[ind][n] != -1){
            return dp[ind][n];
        }

        //pick
        int take = slices[ind] + solve(ind+2,endInd,slices,n-1,dp);
        //not pick
        int notTake = solve(ind+1,endInd,slices,n,dp);

        return dp[ind][n] = max(take,notTake);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k,vector<int> (k,-1));
        int case1 = solve(0,k-2,slices,k/3,dp1);
        vector<vector<int>> dp2(k,vector<int> (k,-1));
        int case2 = solve(1,k-1,slices,k/3,dp2);
        return max(case1,case2);
    }
};