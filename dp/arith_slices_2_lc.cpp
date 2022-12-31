//dp array maps ka array hai ki jisme dp[i] ye batara hai ki ith tak >= length ke subseq jo AP banate hai unka cd aur length store karenge map me.
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long ans = 0;
        vector<unordered_map<long,long>> dp(n);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                long cd = (long)nums[i] - (long)nums[j];
                dp[i][cd]++;

                if(dp[j].count(cd)){
                    //agar same cd ke sath pichli ki kisi dabbe me map ka milta hai to uski vsl ko snd me dalo aur ek khudka 1 add karke ab ith dabbe ke map me daldo.
                    dp[i][cd] += dp[j][cd];
                    ans += dp[j][cd]; 
                }
            }
        }
        return ans;
    }
};