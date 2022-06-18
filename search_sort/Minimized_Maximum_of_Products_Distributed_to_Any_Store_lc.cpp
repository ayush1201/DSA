//The concept is to find again lower bound and upper bound for the binary search to be applied since we can see that there is monotonic behaviour in quantities where minimium is 1 and maximum is max of quantities .Then we will se if the mid is possible solution or not by checking if the count value is greater than given shops it will return false and left of mid will also be returning false so we shift start=mid+1, |||ly if it return true we will save last mid and check for mid less than current mid .
//The complexity is again O(n+log(n)(n)) which is O(nlog(n)).
class Solution {
public:
    bool possible(int mid,vector<int>& quantities,int n){
        int count=0;
        for(int i=0;i<quantities.size();i++){
            if(quantities[i]%mid==0){
                count=count+quantities[i]/mid;
            }
            else{
                count=count+quantities[i]/mid+1;
            }
        }
        if(count<=n)
            return true;
        return false;
    }
    
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int max=-1;
        for(int i=0;i<m;i++){
            if(max<quantities[i]){
                max=quantities[i];
            }
        }
        int start=1;
        int end=max;
        int res;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(possible(mid,quantities,n)){
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