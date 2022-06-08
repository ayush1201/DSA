class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre="";
//First of all we need to sort the string. The first and last words will be most different and if we comnpare them by iterating over them we can get longest common prefix .
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string a=strs[0];
        string b=strs[n-1];
        if(n==0){
            return pre;
        }
//Now iterating over first and last words.
        for(int i=0;i<a.length();i++){
            if(a[i]==b[i]){
                pre=pre+a[i];
            }
            else{
                break;
            }
        }
        return pre;
    }
};