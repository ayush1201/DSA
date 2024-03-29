class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    //concept is just use min heap and get 2 small elements add them and update cost of ropes and put the sum of 2 elements back in pq.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        long long cost = 0;
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            
            long long b = pq.top();
            pq.pop();
            
            cost += a+b;
            pq.push(a+b);
        }
        return cost;
    }
};