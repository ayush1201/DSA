//same concept of lcs and once the length is got ,we can backtrack and print each character while going back and since we need common words to be once so print that only single time.
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // Write your code here.
    int n1 = str1.length();
        int n2 = str2.length();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        //now backtrack and print the characters.
        int i = n1;
        int j = n2;
        string ans;
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans.push_back(str1[i-1]);
                i--;
            }
            else{
                    ans.push_back(str2[j-1]);
                    j--;
                }
            }
        
        //add rest characters which are left due to bound conditions.
        while(i>0){
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(str2[j-1]);
            j--;
        }
        
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};