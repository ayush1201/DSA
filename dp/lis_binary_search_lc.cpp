//ith denotekarega vaha tak ka sabse bada length ka longest increasing subsequence jo nums[i] pe khatam hota ho bas yhi meaning assign karna hai .
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> dp(n,0);
        
        // dp[0] = 1;
        // for(int i=1;i<n;i++){
        //     //ab 0 se i tak loop ek aur marke dekho ki nums[i] kiske peeche lag sakta hai aur maximum length banaye.
        //     int maxLen = 0;
        //     for(int j=0;j<i;j++){
        //         if(nums[j] < nums[i]){
        //             maxLen = max(maxLen,dp[j]);
        //         }
        //     }
        //     //khudko bhi to ginna hai .
        //     dp[i] = 1 + maxLen;
        // }
        // //now find the max len by iterating over dp array because we don't know at what index we will get maxLen.
        // int ans = 1;
        // for(int i=0;i<n;i++){
        //     ans = max(ans,dp[i]);
        // }
        // return ans;

        //binary search optimized approach 
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
            
        }
        return temp.size();
    }
};