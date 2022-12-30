//gap strategy kaam aajayegi but do baar lagani padegi ,first time track rakhne ki konsa part palindrome hai and second time use karenge ki min lines kitni lagani padegi ki sare palindrome ban jaye.
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp1(n,vector<bool> (n,false));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g == 0){
                    //single character always palindrome
                    dp1[i][j] = true;
                }
                else if(g == 1){
                    //two character just check s[i] and s[j] for palindrome.
                    if(s[i] == s[j]){
                        dp1[i][j] = true;
                    }
                    
                }
                else{
                    //characters more than 2 
                    if(s[i] == s[j]){
                        dp1[i][j] = dp1[i+1][j-1];
                    }
                }
            }
        }

        // //now tracking the minimum partitions made to make every part palindrome.
        // vector<vector<int>> dp2(n,vector<int> (n,0));
        // for(int g=0;g<n;g++){
        //     for(int i=0,j=g;j<n;i++,j++){
        //         if(dp1[i][j] == true){
        //             dp2[i][j] = 0;
        //         }
        //         else{
        //             //ab partitions lagao aur dekho kaha lagake answer min milega.
        //             int mini = INT_MAX;
        //             for(int k=i;k<j;k++){
        //                 int left = dp2[i][k];
        //                 int right = dp2[k+1][j];
        //                 mini = min(mini,left+right+1);
        //             }
        //             dp2[i][j] = mini;
        //         }
        //     }
        // }
        // return dp2[0][n-1];

        //optimized approch
        //palindromic suffix nikal lo aur dekhlo baki ke part me kitne cuts lagenge minimum.
        vector<int> dp2(n,0);
        for(int j=1;j<n;j++){
            if(dp1[0][j] == true){
                dp2[j] = 0;
            }
            else{
                int mini = INT_MAX;
            for(int i=j;i>=1;i--){
                //check the suffix which is palindrome so that before that suffix just calculate minimum partition required to make whole palindrome till ith index and store at dp[i].
                if(dp1[i][j] == true){
                    if(mini > dp2[i-1]){
                        mini = dp2[i-1];
                    }
                }
            }
            dp2[j] = mini + 1;
            }
            
        }
        return dp2[n-1]; 
    }
};