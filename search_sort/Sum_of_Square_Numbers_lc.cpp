//Just apply 2 pointer approach and no need to confuse with binary search ,it is similar to the pair sum problem but with squarred values.
//Time complexity is sqrt(n).
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int start=0;
        long long int end=sqrt(c);
        long long int ele=0;
        while(start<=end){
            ele=start*start+end*end;
            if(ele==c){
                return true;
            }
            else if(ele<c){
                start++;
            }
            else{
                end--;
            }
        }
        return false;
        
    }
};