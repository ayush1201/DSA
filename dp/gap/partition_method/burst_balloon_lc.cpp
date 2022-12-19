//gap strategy kaam aayegi yaha bhi.
//isme jis balloon pe hai matlab vo last bacha hai aur uske left aur right ke sare phod chuke hai aur iss tarah se maximum coins collect karo.
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        if(n == 1){
            return nums[0];
        }
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                //agar ek hi balloon ko phodna hai 
                if(g == 0){
                    if(i == 0){
                        dp[i][j] = nums[i] * nums[i+1];
                    }
                    else if(i == n-1){
                        dp[i][j] = nums[i] * nums[i-1];
                    }
                    else{
                        dp[i][j] = nums[i-1] * nums[i] * nums[i+1];
                    }
                }
                else{
                    //matlab do ya zyada balloons phodne hai aur max nikalna hai ki kis order me phode.
                    int maxi = INT_MIN;
                    for(int k=i;k<=j;k++){
                        //bade edge cases hai iss me ki jab kone ke cases handle karre ho to.
                        //ye do partitions kare hai left aur right aur khud.
                        int left = (k == i) ? 0 : dp[i][k-1];
                        int right = (k == j) ? 0 : dp[k+1][j];
                        int khudkoPhodneMe = nums[k];
                        if(i > 0){
                            khudkoPhodneMe = khudkoPhodneMe * nums[i-1];
                        }
                        if(j < n-1){
                            khudkoPhodneMe = khudkoPhodneMe * nums[j+1];
                        }
                        if(maxi < left + right + khudkoPhodneMe){
                            maxi = left + right + khudkoPhodneMe;
                        }
                    }
                    dp[i][j] = maxi;
                }
            }
        }
        return dp[0][n-1];
    }
};