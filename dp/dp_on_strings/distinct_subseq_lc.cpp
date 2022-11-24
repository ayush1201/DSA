//recursion basic , express in i,j and it means that till ith length the number of t strings with jth ending are found. Then explore all possibilty and then sum it all .
class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &dp,string &s,string &t){
        //base case
        if(j < 0){
            return 1;
        }
        if(i < 0){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        //recursion calls
        if(s[i] == t[j]){
            //option of picking and not ppicking
            dp[i][j] = (solve(i-1,j-1,dp,s,t) + solve(i-1,j,dp,s,t));
            return dp[i][j];
        }
        else{
            dp[i][j] = solve(i-1,j,dp,s,t);
            return dp[i][j];
        }
    }
    
    int numDistinct(string s, string t) {
        // vector<vector<int>> dp(s.length(),vector<int> (t.length(),-1));
        // return solve(s.length()-1,t.length()-1,dp,s,t);
        
        //direct tabulation
        vector<vector<double>> dp(s.length()+1,vector<double> (t.length()+1,0)); //double to handle the overflow.
        for(int i=0;i<=s.length();i++){
            dp[i][0] = 1;
        }
        
        for(int j=1;j<=t.length();j++){
            dp[0][j] = 0;
        }
        
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=t.length();j++){
                if(s[i-1] == t[j-1]){
                    //mere paas uthane ka ya nhi uthane ka option hai .
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    //matlab match kiya hi ni to i-1,j se uthao.
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int n = s.length();
        int m = t.length();
        return (int)dp[n][m];
    }
};