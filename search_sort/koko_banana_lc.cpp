//The concept is to search for the search space which will be between 1 and maximum element of piles always in this question. Then we will apply binary search on it and check for possible answer and if it is true than we will store that answer of k as mid in res and change 'end=mid-1' ,since after it all will be accepted as more value of k will produce less hours so we can neglect this part. If it returns false it means values of k less than mid will produce more hours always and hence we need to shift our search space towards right.
//The complexity is same O(nlog(n)).
class Solution {
public:
    
    bool possible(int mid,vector<int>& piles,int h){
        long long int count=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]<=mid){
                count++;
            }
            else{
        if(piles[i]%mid==0){
            count=piles[i]/mid+count;
        }
        else{
            count=piles[i]/mid+count+1;
        }
            }
    }
        if(count<=h)
            return true;
        return false;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        long long int max=-1;
        for(int i=0;i<n;i++){
            if(max<piles[i]){
                max=piles[i];
            }
        }
        long long int start=1;
        long long int end=max;
        long long int res;
        while(start<=end){
            long long int mid=start+(end-start)/2;
            if(possible(mid,piles,h)){
                res=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return res;
        
    }
};