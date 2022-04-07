class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int len=S.length()-1;
        string rev="";
        for(int i=len;i>=0;i--){
            if(S[i]=='.'){
                rev=rev+S.substr(i+1,len-i)+".";
                len=i-1;
                
            }
            if(i==0){
                rev=rev+S.substr(i,len+1);
            }
        }
       // rev=rev+S.substr(0,len);
        return rev;
    } 
};