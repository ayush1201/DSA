//same as LIS with little modification.
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> dp(n,0);
	    dp[0] = arr[0];
	    
	    for(int i=1;i<n;i++){
	        int maxSum = 0;
	        for(int j=0;j<i;j++){
	            if(arr[j] < arr[i]){
	                maxSum = max(maxSum,dp[j]);
	            }
	        }
	        dp[i] = maxSum + arr[i];
	    }
	    int ans = 0;
	    for(int i=0;i<n;i++){
	        ans = max(ans,dp[i]);
	    }
	    return ans;
	}  
};