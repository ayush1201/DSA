//gap strategy and checking the longest substr which is palindrome and printing it.
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool> (n,false));

        //gap strategy for checking palindromic substrings.
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(i == j){
                    dp[i][j] = true;
                }
                else if(j - i == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                    }
                }
                else{
                    if(s[i] == s[j]){
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
            }
        }

        //tracking record the longest substring by taking i and j index so that we can later on print it.
        int maxLen = 0;
        int start,end = 0;
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(dp[i][j] == true){
                    if(maxLen <= j-i+1){
                        maxLen = j-i+1;
                        start = i;
                        end = j;
                    }
                }
            }
        }

        //now getting the substring which has longest length and also it is palindrome.
        string ans = "";
        for(int i=start;i<=end;i++){
            ans += s[i];
        }
        return ans;
    }
};