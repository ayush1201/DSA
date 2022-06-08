//time complexity is O(Nlog(N))
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int start=0;
        int end=people.size()-1;
        int boats=0;
        sort(people.begin(),people.end());
        while(start<=end){
//Checking that if the heaviest and lightest weight sum is less than equal to limit
            if((people[start]+people[end])<=limit){
                start++;
                end--;
                
                
            }
//If the sum is greater than limit it means only heavyweight one can go in that boat.
            else if((people[start]+people[end])>limit){
                end--;
                
            }
            boats++;
        }
       return boats;
    }
};