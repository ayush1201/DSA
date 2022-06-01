class Solution {
public:
    int compress(vector<char>& chars) {
        int count=1;
        int ansindex=0;
        int i=0;
        while(i<chars.size()){
            int j=i+1;
// traverse and increment j till we get different character
            while((j<chars.size())&&(chars[i]==chars[j])){
                j++;
            }
//finding the count by difference of j and i
            count=j-i;
            chars[ansindex++]=chars[i];
//converting count to single value by converting into string
            if(count>1){
                string cnt=to_string(count);
                for(char ch: cnt){
                    chars[ansindex++]=ch;
                }
            }
//incrementing i to last position of j
            i=j;
        }   
        return ansindex;
    }
};