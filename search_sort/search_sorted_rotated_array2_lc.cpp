//Using two pointer start and end ,checking if target is greater than start than increment it and if target is less than end decrement end and additional while loop for neglecting duplicates.
//Time complexity is O(n).
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        if(nums.size()==1){
            if(nums[0]==target){
                return true;
            }
        }
        while(start<end){
            if((nums[start]==target)||(nums[end]==target)){
                return true;
            }
            if(nums[start]<target){
                while((start<end)&&(nums[start]==nums[start+1])){
                    start++;
                }
                start++;
            }
            else if(nums[end]>target){
                while((start<end)&&(nums[end]==nums[end-1])){
                    end--;
                }
                end--;
            }
            else{
                //It means no exist such target in any other conditions.
                break;
            }
        }
        return false;
        
    }  
};