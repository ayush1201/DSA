//dp me hum pichle ugly numbers store jinme hum 2,3,5 multiply karke dekhenge aur min wale ko agla ugly number bana denge aur jo jo same hai values minimum ke un pointers ko aage badayenge.
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;

        for(int i=1;i<n;i++){
            int ans = min(2*dp[p2],min(3*dp[p3],5*dp[p5]));
            dp[i] = ans;
            if(ans == 2*dp[p2])p2++;
            if(ans == 3*dp[p3])p3++;
            if(ans == 5*dp[p5])p5++;
        }
        return dp[n-1];
    }
};