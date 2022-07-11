//time complexity is o(n^2).
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        //sorting the array will be used to apply 2 pointer approach.
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        //base cases
        if(n<3){
            return {};
        }
        
        if(nums[0]>0){
            return {};
        }
        //for fixing one number.
        for(int i=0;i<n;i++){
            if(nums[i] > 0){     //If number fixed is +ve, stop there because we can't make it zero by searching after it.
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]){    //If number is getting repeated, ignore the lower loop and continue.
                continue;
            }
            
            int low=i+1;
            int high=n-1;
            int sum=0;
            while(low<high){
                sum=nums[i]+nums[low]+nums[high];
                if(sum>0){
                    high--;
                }
                else if(sum<0){
                    low++;
                }
                else{
                    ans.push_back({nums[i] , nums[low] , nums[high]});
                    //just iterating low and high till the nums[low] and nums[high] is found in next element .
                    int last_low_occur=nums[low];
                    int last_high_occur=nums[high];
                    while(low<high && nums[low]==last_low_occur){
                        low++;
                    }
                    while(low<high && nums[high]==last_high_occur){
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};