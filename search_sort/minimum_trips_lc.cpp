//Problem in finding the search space and after finding it binary search is applied and if the mid is possible then end=mid-1 since after mid all will be the answer ,and if not possible then all left of mid will not be possible start=mid+1. And in possible check if count greater than equal to toatlTrips since atleast  totalTrips must satisfy as per question.
//Time complexity is again O(nlog(n)).
class Solution {
public:
    
    bool possible(long long mid,vector<int>& time,int totalTrips){
        unsigned long long count=0;
        for(int i=0;i<time.size();i++){
            if(time[i]<=mid)
            count=mid/time[i]+count;
        }
        if(count>=totalTrips)
            return true;
        return false;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        int m=time.size();
        unsigned long long start=1;
        unsigned long long end=1e18;
        unsigned long long res;
        while(start<=end){
            unsigned long long mid=start+(end-start)/2;
            if(possible(mid,time,totalTrips)){
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