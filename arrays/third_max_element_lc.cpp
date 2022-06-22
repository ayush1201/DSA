//The basic solution is create three variables m1,m2,m3 and check if the current number is greater than m1,put m2 value in m3 and m1 value in m2 since the previous largest will become now second largest and second largest will become third largest . |||ly if current is greater than m2 update m3 with m2's value and put current in m2,same do with m3. Now check if after iteration m3 is still LONG_MIN than return m1 else return m3;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        long m1=LONG_MIN;
        long m2=LONG_MIN;
        long m3=LONG_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]==m1||nums[i]==m2||nums[i]==m3)
                continue;
            if(nums[i]>m1){
                m3=m2;
                m2=m1;
                m1=nums[i];
            }
            else if(nums[i]>m2){
                m3=m2;
                m2=nums[i];
            }
            else if(nums[i]>m3){
                m3=nums[i];
            }
        }
       return m3 == LONG_MIN ? m1 : m3;
    }
};