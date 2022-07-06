class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> pair;
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            //checking if the target-nums[i] is there in hashmap .
            if(map.count(target-nums[i])){
                //pushing the indices of two numbers .
                pair.push_back(map[target-nums[i]]);
                pair.push_back(i);
                return pair;
            }
            else{
                //adding that value with index to the hashmap.
                map[nums[i]]=i;
            }
        }
        return {};
    }
};