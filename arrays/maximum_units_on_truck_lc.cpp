//The concept is sort the given 2d array in descending order based on no of units as max boxes will be appearing in the beginning and now just simply iterate over the array to check whether current boxes is less than truckSize and if yes then simply store them in res, and if they exceeds then itertae from 1 to that box and iteratively add number of units till it exceeds the truckSize.
class Solution {
public:
    bool static comparator(vector<int> &x,vector<int> &y){
        return (x[1]>y[1]);
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comparator);
        int ans=0;
        int res=0;
        int n=boxTypes.size();
        int i=0;
        for(i;i<n;i++){
            if(ans+boxTypes[i][0]<=truckSize){
                res+=boxTypes[i][0]*boxTypes[i][1];
                ans+=boxTypes[i][0];
            }
            else{
                break;
            }
        }
        if(i<n){
            int j=1;
            while(ans+j<=truckSize){
                res+=boxTypes[i][1];
                j++;
            }
        }
        return res;
    }
};