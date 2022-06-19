//In recursion we have to find the base case and then if processing part any and the most important recursive relation which is (n-1)+(n-2) here.
class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        return (fib(n-1)+fib(n-2));
    }
};