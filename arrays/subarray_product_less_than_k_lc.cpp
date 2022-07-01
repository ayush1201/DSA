//Concept is to do in O(n) simply make right and left and check at each right that prod should be less than k and ans+=right-left+1 since we have to add new element right and the size of the sub array , and if prod becomes greater then remove nums[left] from prod and increment left.
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int left=0;
        int prod=1;
        int n=nums.size();
        for(int right=0;right<n;right++){
            prod*=nums[right];
            while(prod>=k && left<n){
                prod/=nums[left];
                left++;
            }
            if(prod<k)
                ans+=right-left+1;
        }
        return ans;
    }
};