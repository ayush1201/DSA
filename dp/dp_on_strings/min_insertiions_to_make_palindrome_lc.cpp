//logic is that we have to keep intact the longest palindrome subseq possible and the rest characters will be added all to make the string palindrome, slight modification of longest palindrome subseq.
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        int maxLen = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1] == s[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxLen = max(maxLen,dp[i][j]);
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    maxLen = max(maxLen,dp[i][j]);
                }
            }
        }
        return (n-maxLen);
    }
};