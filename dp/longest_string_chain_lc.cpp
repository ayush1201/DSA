//concept of LIS with slight modification istead of checking for increasing numbers check for string which have difference of one character only.
class Solution {
public:
    bool compare(string &s1,string &s2){
        if(s1.length() - s2.length() != 1){
            return false;
        }
        int n1 = s1.length();
        int n2 = s2.length();

        int i=0,j=0;
        while(i < n1 && j < n2){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if((i == n1 && j == n2) || (i == n1-1 && j == n2)){
            return true;
        }

        return false;

    }

    static bool comp(string &s1,string &s2){
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n = words.size();
        vector<int> dp(n,0);
        dp[0] = 1;

        for(int i=1;i<n;i++){
            int maxLen = 0;
            for(int j=0;j<i;j++){
                //compare words[i] and words[j].
                if(compare(words[i],words[j])){
                    maxLen = max(maxLen,dp[j]);
                }
            }
            dp[i] = 1 + maxLen;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};