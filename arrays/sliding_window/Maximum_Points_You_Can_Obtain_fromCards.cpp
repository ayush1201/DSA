//the main concept is to find the max cards sum from both ends so instead of finding max sum we can traverse a window from starting till end and check for minimum value in it since opposite of maximum is minimum. Then in the end we will return the totsum - minimum value window in the answer.
//Time complexity is O(n).
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totsum=0;
        int n=cardPoints.size();
        int window=n-k;
        int mini=INT_MAX;
        int currWindowsum=0;
        //we will traverse this window and check for minimum value.
        for(int i=0;i<n;i++){
            totsum+=cardPoints[i];
        }
        
        int i=0;
        while(i<window){
            currWindowsum+=cardPoints[i++];
        }
        mini=currWindowsum;
        
        while(i<n){
            currWindowsum+=cardPoints[i];
            currWindowsum-=cardPoints[i-window];
            mini=min(mini,currWindowsum);
            i++;
        }
        return totsum-mini;
    }
};