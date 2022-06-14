//The concept here is if mid is even and element at mid+1 is equal than left of mid is always double digits or also if mid is odd and mid-1 element is equal to element at mid than increment start else end=mid.
//Time complexity is O(logn)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;

        while(start<end){
            int mid=start+(end-start)/2;
            // if((nums[mid]!=nums[mid+1])&&(nums[mid]!=nums[mid-1])){
            //     return nums[mid];
            // }
            if(((mid%2==0)&&(nums[mid]==nums[mid+1]))||((mid%2==1)&&(nums[mid]==nums[mid-1])))             {
               start=mid+1; 
            }
            else{
                end=mid;
            }
        }
        return nums[start];
    }
};