//gap method yaha kaam aagya, main logic hai ki dekho kaha pe partition kar sakte hai ki all parts library ke words se match ho jaye.
//ye brute force solution hai aur slow chala hai .
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int w = wordDict.size();
        unordered_map<int,string> mp(w);
        vector<vector<bool>> dp(n,vector<bool> (n,false));

        for(int i=0;i<w;i++){
            mp[i] = wordDict[i];
        }

        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                string word = "";
                for(int k=i;k<=j;k++){
                    word.push_back(s[k]);
                }
                for(auto &it : mp) { 
                 if(it.second == word) { 
                  dp[i][j] = true; 
                  } 
                  else{
                      for(int k=i;k<j;k++){
                        if(dp[i][k] == true && dp[k+1][j] == true){
                            dp[i][j] = true;
                            break;
                        }
                    }
                  }
                } 
                // else{
                //     for(int k=i;k<j;j++){
                //         if(dp[i][k] == true && dp[k+1][j] == true){
                //             dp[i][j] = true;
                //             break;
                //         }
                //     }
                // }
            }
        }
        return dp[0][n-1];
    }
};