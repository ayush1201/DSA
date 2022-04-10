void sort012(int *arr, int n)
{
   //   Write your code here
	int low=0;
	int mid=0;
	int last=n-1;
	while(mid<=last){
		if(arr[mid]==0){
			swap(arr[low],arr[mid]);
			low++;
			mid++;
		}
		else if(arr[mid]==1){
			mid++;
		}
		else if(arr[mid]==2){
			swap(arr[mid],arr[last]);
			last--;
		}
	}
}