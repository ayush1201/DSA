//gap strategy method aur partitions ke left aur partitions ke right me deklo answer aur khudka score to easy hai i*j*k..
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g == 0 || g == 1){
                    //matlab triangle possible hhi nhi hai.
                    dp[i][j] = 0;
                }
                else{
                    //ab partitions karke minimum answer lao.
                    int mini = INT_MAX;
                    for(int k=i+1;k<j;k++){
                        int left = dp[i][k];
                        int right = dp[k][j];
                        int scoreKthTriangle = values[i] * values[k] * values[j];
                        mini = min(mini,left+right+scoreKthTriangle);
                    }
                    dp[i][j] = mini;
                }
            }
        }
        return dp[0][n-1];
    }
};