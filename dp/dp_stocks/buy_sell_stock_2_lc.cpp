//we have infinite transactions so at every dip we buy and every tip we sell.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bd = 0;
        int sd = 0;
        int profit = 0;
        
        for(int i=1;i<prices.size();i++){
            if(prices[i] >= prices[i-1]){
                sd++;
            }
            else{
                //profit collect karo.
                profit = profit + prices[sd] - prices[bd];
                bd = i;
                sd = i;
            }
        }
        return profit = profit + prices[sd] - prices[bd];
    }
};