//Concept is rather than adding 1 to n-1 elements we can simply delete 1 from 1 element .We will find minimum element and subtract every element from min which is equal to decrementing 1 in each move.
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=INT_MAX;
        int sum=0;
        for(int i:nums){
            mini = min(mini,i);
        }
        for(int i:nums){
            sum+=i-mini;
        }
        return sum;
        
    }
};