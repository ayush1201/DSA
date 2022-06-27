#include<iostream>
using namespace std;

int partition(int *arr,int start,int end){
    int pivot=arr[start];
    int count=0;
    for(int i=start+1;i<=end;i++){
        if(arr[i]<pivot)
         count++;
    }
    int pivotindex=start+count;
    swap(arr[pivotindex],arr[start]);
    int i=start;
    int j=end;
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<pivot){
         i++;
        }
        while(arr[j]>pivot){
         j--;
        }
        if(i<pivotindex && j>pivotindex)
         swap(arr[i++],arr[j--]);  
    }
    return pivotindex;

}

void quickSort(int *arr,int start,int end){
    if(start>=end)
     return; 
    //creating partition
    int part=partition(arr,start,end);
    //recursive call for left side of partition
    quickSort(arr,start,part-1);
    //recursive call for right side of partition
    quickSort(arr,part+1,end); 
}

int main(){

    int arr[5]={3,6,1,2,5};
    int n=5;
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}