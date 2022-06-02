class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        int start=0;
        if(nums.size()==0){
            return 0;
        }
        else{
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[start++]=nums[i];
            }
        }
      }
        return start;
    }
};