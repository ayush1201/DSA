//same concept of longest common subsequence but with just reversed of given string as we have to find common subsequences in given dtring and its reverse.
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        string s1 = s;
        reverse(s.begin(),s.end());
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                //if matching
                if(s1[i-1] == s[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                //not matching
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};