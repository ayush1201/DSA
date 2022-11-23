//concept hai ki ith,jth denote karega ki vaha se end tak kitna max area possible hai ,so uss position pe agar zero hai to simply 0 daldo dp array me warna chack karo dp[i+1][j+1],dp[i][j+1],dp[i+1][j] me se jo chota hai vo use bada karne se rokenge to 1 add karke daldo dp[i][j] par.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        int maxArea = 0;
        
        
        //base cases.
        for(int i=m-1;i>=0;i--){
            if(matrix[i][n-1] == '1'){
                dp[i][n-1] = 1;
            }
            else{
                dp[i][n-1] = 0;
            }
            maxArea = max(dp[i][n-1],maxArea);
        }
        
        for(int j=n-1;j>=0;j--){
            if(matrix[m-1][j] == '1'){
                dp[m-1][j] = 1;
            }
            else{
                dp[m-1][j] = 0;
            }
            maxArea = max(dp[m-1][j],maxArea);
        }
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(matrix[i][j] == '0'){
                    dp[i][j] = 0;
                    // int maxi = max(dp[i+1][j+1],max(dp[i+1][j],dp[i][j+1]));
                    // maxArea = maxi*maxi;
                }
                else{
                    dp[i][j] = 1 + min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
                    maxArea = max(maxArea,dp[i][j]*dp[i][j]);
                }
            }
        }
        return maxArea;
    }
};