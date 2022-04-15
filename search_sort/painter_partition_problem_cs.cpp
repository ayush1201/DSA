bool ispossible(vector<int> boards,int k,int mid){
	int paintblock=0;
	int painter=1;
	for(int i=0;i<boards.size();i++){
		if(paintblock+boards[i]<=mid){
			paintblock=paintblock+boards[i];
		}
		else{
			painter++;
		if(painter>k || boards[i]>mid)
			return false;
			paintblock=boards[i];
		}
	}
	return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
	int start=0;
	int sum=0;
	int ans=-1;
	//finding the search space 
	for(int i=0;i<boards.size();i++){
		sum=sum+boards[i];
	}
	int end=sum;
	int mid=start+(end-start)/2;
	while(start<=end){
		if(ispossible(boards,k,mid)){
			ans=mid;
			end=mid-1;
		}
		else{
			start=mid+1;
		}
		mid=start+(end-start)/2;
	}
	return ans;
}