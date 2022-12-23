//acha tha question bas sort karne se baat aasan pad gayi aur normal pick not pick laga dia recursion me.
class Solution {
public:
    int solve(int ind,int time,vector<int>& s,vector<vector<int>> &dp){
        //base case
        if(ind >= s.size()){
            return 0;
        }

        if(dp[ind][time] != -1){
            return dp[ind][time];
        }


        //two options pick and not pick.
        int pick = s[ind]*time + solve(ind+1,time+1,s,dp);
        int notPick = solve(ind+1,time,s,dp);
        dp[ind][time] = max(pick,notPick);
        return dp[ind][time];
    }
    int maxSatisfaction(vector<int>& s) {
        int n = s.size();
        sort(s.begin(),s.end());
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return solve(0,1,s,dp);
    }
};