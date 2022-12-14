//isme slight change hai ki phele dp aur count array poora 1 se fill kardo aur har ek i se choti value ke liye calculate karo length aur count.
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        //storing lis in dp array.

        for(int i=1;i<n;i++){
            int maxLen = 0;
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
                else if(nums[j] < nums[i] && dp[i] == dp[j] + 1){
                    count[i] += count[j];
                }
            }
        }

        //ab max length dekho aur uske occurrances dekho.
        int maxLen = 0;
        for(int i=0;i<n;i++){
            maxLen = max(maxLen,dp[i]);
        }
        int result = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == maxLen){
                result += count[i];
            }
        }

        return result;
    }
};