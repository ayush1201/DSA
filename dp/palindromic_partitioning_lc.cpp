//palindromic prefix ka concept lagana hai ,string me palin prefix ko uthao aur usko res me dalo aur aage call lagao baki ki string palin prefix dekne ke liye.
class Solution {
public:
    bool isPalin(string s){
        int i=0;
        int j=s.size()-1;
        while(i <= j){
            if(s[i] != s[j]){
                return  false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(string s,vector<vector<string>> &ans,vector<string> res){
        if(s.size() == 0){
            ans.push_back(res);
            return;
        }

        for(int i=0;i<s.size();i++){
            string prefix = s.substr(0,i+1);
            string rem = s.substr(i+1);
            if(isPalin(prefix)){
                res.push_back(prefix);
                solve(rem,ans,res);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> res;
        vector<vector<string>> ans;
        solve(s,ans,res);
        return ans;
    }
};