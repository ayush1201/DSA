//isme hamne dp banaya hai longest length ka track rakne ke liye aur trackIndex banaya hai indices ka track rakne ke liye jo previous hai ith ke aur jo contri kar sakte hai lamba banane me.
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        vector<int> trackIndex(n,0);
        sort(nums.begin(),nums.end());
        dp[0] = 1;
        trackIndex[0] = 0;

        for(int i=1;i<n;i++){
            int maxLen = 0;
            int maxIndex = 0;
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0){
                    maxLen = max(maxLen,dp[j]);
                    if(maxLen == dp[j]){
                        maxIndex = j;
                    }
                }
            }
            if(maxLen == 0){
                dp[i] = 1 + maxLen;
                trackIndex[i] = i;
            }
            else{
                dp[i] = 1 + maxLen;
                trackIndex[i] = maxIndex;
            }

        }
        //we have kept record of longest divisible subsequence and inices also now we have to backtrack in order to print it.
        vector<int> ans;
        int index = INT_MIN;
        int longestLen = 0;
        for(int i=0;i<n;i++){
            if(dp[i] >= longestLen){
                longestLen = dp[i];
                index = i;
            }
        }

        ans.push_back(nums[index]);
        //now from index backtrack.
        while(index != trackIndex[index]){
            index = trackIndex[index];
            ans.push_back(nums[index]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};