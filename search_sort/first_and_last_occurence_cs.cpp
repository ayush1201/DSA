int first_occur(vector<int>& arr,int n,int key){
	int start=0;
	int end=n-1;
	int mid=start+(end-start)/2;
	int ans=-1;
	while(start<=end){
		if(arr[mid]==key){
			ans=mid;
			end=mid-1;
		}
		else if(arr[mid]<key){
			start=mid+1;
		}
		else{
			end=mid-1;
		}
		mid=start+(end-start)/2;
	}
	return ans;
}
int last_occur(vector<int>& arr,int n,int key){
	int end=n-1;
	int start=0;
	int mid=start+(end-start)/2;
	int ans=-1;
	while(start<=end){
		if(arr[mid]==key){
			ans=mid;
			start=mid+1;
		}
		else if(arr[mid]<key){
			start=mid+1;
		}
		else{
			end=mid-1;
		}
		mid=start+(end-start)/2;
	}
	return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
	pair<int, int> p;
	p.first=first_occur(arr,n,k);
	p.second=last_occur(arr,n,k);
	return p;
}