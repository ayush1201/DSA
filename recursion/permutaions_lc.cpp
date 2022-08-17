//just swap the index element with rest elements in every loop iteration.Just swap the main nums array elements using recursion.
class Solution {
public:
    
    void solve(vector<int>& nums,vector<vector<int>> &ans,int index){
        //base case
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        //processing
        for(int i=index;i<nums.size();i++){
            //swap the values for possible combinations.
            swap(nums[index],nums[i]);
            
            //recursive call
            solve(nums,ans,index+1);
            //backtrack so swap again.
            swap(nums[index],nums[i]);
            
            
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        
        solve(nums,ans,0);
        return ans;
    }
};