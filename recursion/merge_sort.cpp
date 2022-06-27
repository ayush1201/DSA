#include<iostream>
using namespace std;


void merge(int arr[],int start,int end){
    int mid=start+(end-start)/2;
    int len1=mid-start+1;
    int len2=end-mid;
    int *first=new int[len1];
    int *second=new int[len2];
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
}

void mergsort(int arr[],int start,int end){
    //base case
    int mid=start+(end-start)/2;
    if(start>=end)
    return ;
    //seperate left part
    mergsort(arr,start,mid);
    //seperate right part
    mergsort(arr,mid+1,end);
    //merging 2 arrays
    merge(arr,start,end);
}


int main(){
   int arr[5]={3,1,6,2,9};
   int n=5;
   int start=0;
   int end=n-1;
   mergsort(arr,start,end);
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }cout<<endl;
   return 0;
}