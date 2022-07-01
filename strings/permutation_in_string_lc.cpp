class Solution {
public:
    bool check(int a[],int b[]){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        //creating array of size 26 .
        int a[26]={0};
        int windowSize=s1.length();
        for(int i=0;i<s1.length();i++){
            a[s1[i]-'a']++;
        }
        
        //now just making another array which will be used to store occurances of s2 string in it and each iteration we will compare both the made arrays to check whether both are equal.
        int i=0;
        int b[26]={0};
        int j=windowSize;
        while(i<j && i<s2.length()){
            b[s2[i]-'a']++;
            i++;
        }
        if(check(a,b))
            return true;
        
        while(i<s2.length()){
            b[s2[i]-'a']++;
            b[s2[i-j]-'a']--;
            if(check(a,b))
                return  true;
            i++;
        }
        
        return false;
    }
};