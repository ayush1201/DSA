//jis point pe khade hai matlab uss din bechna mendatory hai aur usse phele ke dino me se sabse min day pe khareeda hoga.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_day = INT_MAX;
        int op = 0;
        int pist = 0; //profit if sell today.
        
        for(int i=0;i<prices.size();i++){
            //pist = prices[i];
            if(prices[i] > min_day){
                pist = prices[i] - min_day;
            }
            else{
                pist = 0;
            }
             
            op = max(pist,op); //overall profit
            min_day = min(min_day,prices[i]); //min_day ko update karo har step pe.
        }
        return op;
    }
};