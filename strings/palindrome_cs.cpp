char tolower(char ch){
        if(ch>='a'&&ch<='z'){
            return ch;
        }
        else{
            char temp=ch-'A'+'a';
            return temp;
        }
    }
bool checkPalindrome(string s)
{
    // Write your code here.
    int start=0;
    int end=s.size()-1;
    
    while(start<end){
        if(isalnum(s[start])==0)
            start++;
        else if(isalnum(s[end])==0)
            end--;
        else if(tolower(s[start])!=tolower(s[end])){
            return false;
        }
        else{
            start++;
            end--;
        }
        
    }
    return true;
}