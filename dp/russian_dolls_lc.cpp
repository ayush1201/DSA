//same as maximum non overlapping bridges difference is that width and height both must be greater than previous envelopes in order to occupy it.
//use of comparator function and sorting based on width and having same width will be sorted on decreasing heights so that it won't count in making envelopes.
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),cmp);
        int n = env.size();
        // vector<int> dp(n,0);
        // dp[0] = 1;

        // for(int i=1;i<n;i++){
        //     int maxLen = 0;
        //     for(int j=0;j<i;j++){
        //         if(env[i][0] > env[j][0] && env[i][1] > env[j][1]){
        //             maxLen = max(maxLen,dp[j]);
        //         }
        //     }
        //     dp[i] = 1 + maxLen;
        // }
        // int ans = 0;
        // for(int i=0;i<n;i++){
        //     ans = max(ans,dp[i]);
        // }
        // return ans;

        //optimized
        //binary search
        vector<int> temp;
        temp.push_back(env[0][1]);
        for(int i=1;i<n;i++){
            if(env[i][1] > temp.back()){
                temp.push_back(env[i][1]);
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),env[i][1]) - temp.begin();
                temp[ind] = env[i][1];
            }
        }
        return temp.size();
    }
};