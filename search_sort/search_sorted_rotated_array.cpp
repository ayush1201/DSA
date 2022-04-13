int findPosition(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
	int start=0;
	int end=n-1;
	int mid=start+(end-start)/2;
	int pivot;
	while(start<end){
		if(arr[mid]>=arr[0]){
			start=mid+1;
		}
		else{
			end=mid;
		}
		mid=start+(end-start)/2;
	}
	pivot=start;
	if(k>=arr[pivot]&&k<=arr[n-1]){
		start=pivot;
		end=n-1;
		mid=start+(end-start)/2;
		while(start<=end){
			if(arr[mid]==k){
				return mid;
			}
			else if(arr[mid]>k){
				end=mid-1;
			}
			else{
				start=mid+1;
			}
			mid=start+(end-start)/2;
		}
		return -1;
	}
	else{
		start=0;
		end=pivot;
		mid=start+(end-start)/2;
		while(start<=end){
			if(arr[mid]==k){
				return mid;
			}
			else if(arr[mid]>k){
				end=mid-1;
			}
			else{
				start=mid+1;
			}
			mid=start+(end-start)/2;
		}
		return -1;
	}
}

