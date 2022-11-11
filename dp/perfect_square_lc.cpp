class Solution {
public:
    int numSquares(int n) {
        //tabulation
        int cnt = 0;
        
        //ye sare edge cases hai fass rahe the 
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        if(n == 3){
            return 3;
        }
        
        for(int i=1;i<=n/2;i++){
            if(i*i <= n){
                cnt++;
            }
        }
        vector<int> store(cnt,0);
        
        //storing the elements in the array store over which we have to make combinations to make n.
        for(int i=1;i<=n/2;i++){
            if(i*i <= n){
                store[i-1] = i*i;
            }
        }
        
        //ye dp array hai simply combination sum ki tarah karlia 
        vector<int> dp(n+1,0);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            int minNumbers = 1e7;
            for(int j=0;j<store.size();j++){
                if(dp[i-store[j] >= 0]){
                    minNumbers = min(minNumbers,(dp[i-store[j]] + 1));
                }
                
            }
            dp[i] = minNumbers;
        }
        return dp[n];
    }
};