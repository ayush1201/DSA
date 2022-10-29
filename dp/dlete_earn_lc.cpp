//same as house robber problem ,just check count of every element and remove all duplicates of elements and then do tabulation by include and exclude concept at ervery element with certain conditions.
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        //tabulation.
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        vector<int> nums2;
        //single occurances of nums element in nums2.
        for(auto i:mp){
            nums2.push_back(i.first);
        }
        
        sort(nums2.begin(),nums2.end());
        
        vector<vector<int>> dp(2,vector<int> (nums2.size(),-1));
        //exclude 
        dp[0][0] = 0;
        //include
        dp[1][0] = nums2[0]*(mp[nums2[0]]);
        
        for(int i=1;i<nums2.size();i++){
            dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
            
            if(nums2[i] == nums2[i-1] + 1){
                dp[1][i] = nums2[i]*(mp[nums2[i]]) + dp[0][i-1];
            }
            else{
                dp[1][i] = nums2[i]*(mp[nums2[i]]) + max(dp[0][i-1],dp[1][i-1]);
            } 
        }
        
        return max(dp[0][nums2.size()-1],dp[1][nums2.size()-1]);
    }
};