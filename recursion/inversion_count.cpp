#include<iostream>
using namespace std;


int merge(int arr[],int start,int end){
    int mid=start+(end-start)/2;
    int len1=mid-start+1;
    int len2=end-mid;
    int *first=new int[len1];
    int *second=new int[len2];
    int inv=0;
    //copy values of two arrays in first and second.
    int mainindex=start;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainindex++];
    }
    mainindex=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainindex++];
    }
    //merge
    int index1=0;
    int index2=0;
    mainindex=start;
    while((index1<len1)&&(index2<len2)){
        if(first[index1]<second[index2]){
            arr[mainindex++]=first[index1++];
        }
        else{
            arr[mainindex++]=second[index2++];
            inv+=len1-index1;
        }
    }
    //checking if any one of the 2 arrays finishes first then the remaining array values will be inserted in main array as it is.
    while(index1<len1){
        arr[mainindex++]=first[index1++];
    }
    while(index2<len2){
        arr[mainindex++]=second[index2++];
    }
    delete []first;
    delete []second;
    return inv;
}

int mergsort(int arr[],int start,int end){
    for(int i=start;i<=end;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //base 
    int mid=start+(end-start)/2;
    if(start>=end)
    return 0;
    int inv=0;
    //seperate left part
    inv+=mergsort(arr,start,mid);
    //seperate right part
    inv+=mergsort(arr,mid+1,end);
    //merging 2 arrays
    inv+=merge(arr,start,end);
    return inv;
}


int main(){
   int arr[4]={8,4,2,1};
   int n=4;
   int start=0;
   int end=n-1;
   int ans=mergsort(arr,start,end);
   cout<<"The inversion count is :"<<ans<<endl;
   return 0;
}