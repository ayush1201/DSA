//Concept is just check if all array contains negative then simply return max of all negatives , and if not then simply check when the sum becomes less than zero make it zero and in every step  store max(ans,sum) in ans.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0;
        int n = nums.size();
        int ans = INT_MIN;
        int allNeg = 1;
        
        //loop to check if all elements are negative then return the maximum of negative.
        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                allNeg = 0;
                break;
            }
            ans = max(ans,nums[i]);
        }
        
        if(allNeg == 1){
            return ans;
        }
        else{
            ans = INT_MIN;
            //means all are not negative then process the algorithm.
            for(int i=0;i<n;i++){
                currsum += nums[i];
                
                //if currsumm becomes negative make it zero as till now the sum will contribute less big from further.
                if(currsum < 0){
                    currsum = 0;
                }
                
                ans = max(ans,currsum);
            }
        }
        return ans;
    }
};