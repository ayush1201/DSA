//Time complexity is O(n).
//Simple use of two pointers and check whether given sum is less than ,greater than or equal to.
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first=0;
        int last=numbers.size()-1;
        vector<int> ans;
        while(first<last){
            if(numbers[first]+numbers[last]>target){
                last--;
            }
            else if(numbers[first]+numbers[last]<target){
                first++;
            }
            else{
                ans.push_back(first+1);
                ans.push_back(last+1);
                first++;
                last--;
                return ans;
            }
        }
        return ans;
    }
};