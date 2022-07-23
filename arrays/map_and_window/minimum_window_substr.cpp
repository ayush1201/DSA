//the main concept is traversing t string and store every char count in map. Then traverse along s string making window with the help of start and end pointers. Increment count until it becomes equal to t.length(), and then increment start pointer till the substring of s is possible in t.
class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0;
        int minlen = INT_MAX;
        int count = 0;
        int minstart = 0;
        unordered_map<char,int> mp;
        //storing chars with their occurances of t in map.
        for(auto ch: t) mp[ch]++;
        for(int end=0;end<s.length();end++){
            //means that char of s string is present in t.
            if(mp[s[end]]>0)
                count++;
            //reducing that char.
            mp[s[end]]--;
            
            if(count==t.length()){
                // Note that negative values in map indicate the key char is not present in t, but present in s. And hence leading chars in s with negative values are insignificant.
                while(start<end && mp[s[start]]<0){
                    mp[s[start]]++;
                    start++;
                }
                if(end-start+1<minlen){
                    minlen = end-start+1;
                    minstart = start;
                }
                // reduce the window size by incrementing start, reducing mp[s[start]] value
                mp[s[start]]++;
                start++;
                count--;
            }
        }
        
        if(minlen==INT_MAX) return "";
        return s.substr(minstart, minlen);
    }
};