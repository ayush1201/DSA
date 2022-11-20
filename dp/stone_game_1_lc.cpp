//same concept of chunks part 1 concept of impact.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for(int i=0;i<n-1;i++){
            ans = max(ans,i+nums[i]);
            //it means after this no movement possible and hence cannot reach the end.
            if(ans == i){
                return false;
            }
        }
        return true;
    }
};