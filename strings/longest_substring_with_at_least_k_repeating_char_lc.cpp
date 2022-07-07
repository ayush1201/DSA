//Recursion and divide and conquer.
class Solution {
public:
    
    
    int longestSubstring(string s, int k) {
        return solver(s,0,s.length(),k);
    }
    
    int solver(string s,int start,int end,int k){
        //base case
        if(end-start < k)
            return 0;
        
        vector<int> count(26,0);
        //storing the occurences of characters of string and will check for unique character having less than k.
        for(int i=start;i<end;i++){
            count[s[i]-'a']++;
        }
        for(int i=start;i<end;i++){
            //checking for the character occurred less than k times.
            if(count[s[i]-'a']<k){
               int j=i+1;
            //checking if there are more consecutive such characters occurred less than k.    
            while(j<end && count[s[j]-'a']<k){
                j++;
            }
            //return the part which is maximum over the other.    
            return max(solver(s,start,i,k),solver(s,j,end,k));
            }
        }
        //if no character found with occurrence less than k simply return end-start.
        return end-start;
    }
};