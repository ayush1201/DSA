class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=rocks.size();
        vector<int> difference(n);
        
        int maxbags=0;
        for(int i=0;i<n;i++){
            difference[i]=capacity[i]-rocks[i];
        }
        //we are sorting since we are trying to fill maximum bags so starting with low difference will need less additional rocks and will be able to fill maximum bags to full capacity.
        sort(difference.begin(),difference.end());
        for(int i=0;i<n;i++){
            if(difference[i]<=additionalRocks){
                additionalRocks-=difference[i];
                difference[i]=0;
                maxbags++;
            }
        }
        return maxbags;
    }
};