//The concept here is also same of binary search just find the search space ,the minimum is 1 and maximum is max of candies. We will check if mid is possible solution then start=mid+1 since we have to find the maximum candies allocated. If selected mid results is less children return false otherwise return true .
//The complexity is O(nlog(n)).
class Solution {
public:
    bool possible(int mid,vector<int>& candies,long long k){
        long long count=0;
        for(int i=0;i<candies.size();i++){
            count=count+candies[i]/mid;
            
        }
        if(count>=k)
            return true;
        return false;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        long long m=candies.size();
        long long max=INT_MIN;
        long long sum=0;
        long long res;
        for(int i=0;i<m;i++){
            sum+=candies[i];
        }
//Checking if candies are less than children simply return 0.        
        if(sum<k){
            return 0;
        }
        else{
        for(int i=0;i<m;i++){
            if(max<candies[i]){
                max=candies[i];
            }
        }
        long long start=1;
        long long end=max;
        
        while(start<=end){
            long long mid=start+(end-start)/2;
            if(possible(mid,candies,k)){
                res=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
          }
        }
        return res;
    }
};