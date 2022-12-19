//gap strategy based - whenever i+1 aur j-1 pe depend karra hota hai answer to gap pel do.
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool> (n,false));
        int cnt = 0;

        //diagonal traversal hona chahiye warna gadbad ho jayegi answer me.
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;j++,i++){
                if(i == j){
                    dp[i][j] = true;
                    cnt++;
                }
                else if(j - i == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                        cnt++;
                    }
                }
                else{
                    if(s[i] == s[j]){
                        dp[i][j] = dp[i+1][j-1];
                        if(dp[i][j] == true)cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};