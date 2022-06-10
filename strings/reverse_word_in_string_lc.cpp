//time complexity is O(N) and space is O(N).
//We will traverse from back by two pointer and just print the word in new string.
class Solution {
public:
    string reverseWords(string s) {
        string res;
        int N=s.length();
        int i=N-1;
        while(i>=0){
            while((i>=0)&&(s[i]==' ')){
                i--;
            }
            if(i<0){
                break;
            }
            int j=i-1;
             while((j>=0)&&(s[j]!=' ')){
                 j--;
             }
            string sub=s.substr(j+1,i-j);
            if(res.length()==0){
                res=sub;
            }
            else{
                res=res+ " " + sub;
            }
            i=j-1;
        }
        
        return res;
    }
};