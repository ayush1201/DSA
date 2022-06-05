// Time complexity is O(n*log(log(n))
class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        vector<bool> prime(n+1,true);
        prime[0]=prime[1]=false;
        for(int i=2;i<n;i++){
//it will check if number is prime then it will enter into another loop of multiples . 
            if(prime[i]){
                count++;
            
            for(int j=i*2;j<n;j=j+i){
                prime[j]=0;
            }
        }
      }
        return count;
    }
};s