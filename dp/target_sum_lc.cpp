//partitions with given sum concept
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int tot = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            tot += nums[i];
        }
        if((tot-target)%2==0){
            int tar = (tot-target)/2;
            //tabulation
            vector<vector<int>> dp(n,vector<int> (tar+1,0));
            for(int j=0;j<=tar;j++){
                if(nums[0] == 0 && j == 0){
                    dp[0][j] = 2;
                }
                if(nums[0] == j || j == 0){
                    dp[0][j] = 1;
                }
            }
            
            for(int i=1;i<n;i++){
                for(int j=0;j<=tar;j++){
                    int nottake = dp[i-1][j];
                    int take = 0;
                    if(nums[i] <= j){
                        take = dp[i-1][j-nums[i]];
                    }
                    dp[i][j] = take + nottake;
                }
            }
            return dp[n-1][tar];
        }
        return 0;
        
    }
};