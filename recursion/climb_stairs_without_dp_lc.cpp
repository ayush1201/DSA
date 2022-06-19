//Just solve for one caase and find the relation ,and also find the base case .
class Solution {
public:
    int climbStairs(int n) {
//base case
        if(n<0){
            return 0;
        }

        if(n==0)
            return 1;
//Recursive relation is if we are standing on nth stair ,only two possibilities are there we might have jumped 1 step or we have jumped 2 steps.
        int ans=climbStairs(n-1)+climbStairs(n-2);
        
        return ans;
    }
};