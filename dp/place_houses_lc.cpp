//simple use directly tabulation concept 2d-DP.
class Solution {
public:
    #define ll long long
    ll mod = 1e9 + 7;
    int countHousePlacements(int n) {
        vector<vector<ll>> dp(2,vector<ll> (n,0));
        
        //base cases when we place and not place at 0th
        dp[0][0] = 1;
        dp[1][0] = 1;
        
        for(int i=1;i<n;i++){
            //0th row means we do not place house at ith position
            dp[0][i] = dp[0][i-1]%mod + dp[1][i-1]%mod;
            //1st row means we place house at ith position means we have not placed house at i-1 position.
            dp[1][i] = dp[0][i-1]%mod;
        }
        ll ans = dp[0][n-1] + dp[1][n-1];
        //we have taken only one side and squared that ans.
        ll res = ((ans%mod)*(ans%mod))%mod;
        return res;
    }
};