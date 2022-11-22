//use table and each ith index will denote from that ith index min jumps to reach the end.
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        
        for(int i=n-2;i>=0;i--){
            int minJumps = 1e7;
            if(nums[i] != 0){
                for(int jumps=1;jumps<=nums[i];jumps++){
                    if(i+jumps <= n-1){
                       minJumps = min(minJumps,1+dp[i+jumps]);
                    }

                }
            }
            
            dp[i] = minJumps;
            
        }
        return  dp[0];
    }
};