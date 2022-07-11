//long long is used to chck the overflow condition and negative sign will automatically be taken care of.
class Solution {
public:
    int reverse(int x) {
        long long res=0;
        while(x){
            res=res*10+x%10;
            x=x/10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};