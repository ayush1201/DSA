class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int j=0;
        int s=nums.size();
        while(i<s){
            int tmp=0;
            j=i;
            while((j<s-1)&&(nums[j]==0)){
                j++;
            }
            tmp=nums[j];
            nums[j]=nums[i];
            nums[i]=tmp;
            i++;
        }
    }
};