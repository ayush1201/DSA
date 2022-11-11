class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int lastDay = days[n-1];
        int firstDay = days[0];
        vector<int> dp(lastDay+31,0);
        vector<int> trackDays(366,0);
        
        for(int i=0;i<n;i++){
            trackDays[days[i]] = 1;
        }
        
        //base case
        dp[lastDay] = min(costs[0],min(costs[1],costs[2]));
        for(int i=lastDay-1;i>=firstDay;i--){
            if(trackDays[i] == 1){
                dp[i] = min(dp[i+1]+costs[0],min(dp[i+7]+costs[1],dp[i+30]+costs[2]));
            }
            else{
                dp[i] = dp[i+1];
            }
        }
        return dp[firstDay];
    }
};