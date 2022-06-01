class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int maxi=-1;
        int ans=0;
        int num=0;
        int max[26]={0};
        for(int i=0;str[i]!='\0';i++){
            num=str[i]-'a';
            max[num]++;
        }
        for(int i=0;i<26;i++){
            if(max[i]>maxi){
                maxi=max[i];
                ans=i;
            }
        }
        return ans+'a';
    }

};