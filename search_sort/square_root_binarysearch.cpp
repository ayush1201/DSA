
int sqrtN(long long int N)
{
    // Write your code here.
	int start=0;
	int end=N;
	unsigned long long int mid=start+(end-start)/2;
	unsigned long long int ans=-1;
	if(N==2){
		return 1;
	}
	while(start<=end){
		unsigned long long int square=mid* mid;
		if(square==N){
			return mid;
		}
		else if(square>N){
			end=mid-1;
		}
		else{
			ans=mid;
			start=mid+1;
		}
		mid=start+(end-start)/2;
	}
	return ans;
}