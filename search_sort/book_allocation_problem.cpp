bool ispossible(vector<int> arr,int n,int m,int mid){
    int pagesum=0;
    int count=1;
    for(int i=0;i<n;i++){
        if(arr[i]+pagesum<=mid){
            pagesum=pagesum+arr[i];
        }
        else{
            count++;
            if(count>m || arr[i]>mid){
               return false;
            }
            pagesum=arr[i];
        }
        
    }
    return true;

}


int allocate_books(vector<int> arr,int n){
    int start=0;
    int ans=-1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    int end=sum;
    int mid=start+(end-start)/2;
    while(strat<=end){
        if(ispossible(arr,n,m,mid)){
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