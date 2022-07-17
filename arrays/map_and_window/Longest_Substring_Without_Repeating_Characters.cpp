class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int store[256]={0};
        int n=s.length();
        int ans=0;
        
        while(right<n){
        //storing the occurrances of s[right] in store array .     
            store[s[right]]++;
        //checking if the occurrence becomes greater than 1.    
            while(store[s[right]]>1){
                
                store[s[left]]--;
                left++;
            }
        //store the greater value than previous stored answer.
            ans=max(ans,right-left+1);
            right++;
                
        }
        return ans ;
    }
};