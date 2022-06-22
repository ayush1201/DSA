#include<iostream>
using namespace std;

void selection(int i,int arr[],int n){
    //base case
    if(i==n-1){
        return ;
    }
    //one case is solved which will put biggest element at last.
    for(int x=0;x<n;x++){
        cout<<arr[x]<<" ";
    }
    cout<<endl;
    int index=i;
    for(int j=i+1;j<n;j++){
        if(arr[index]>arr[j]){
            index=j;
        }
    }
    swap(arr[index],arr[i]);
    //recursive call
    selection(i+1,arr,n);
}

int main(){
    int arr[5]={3,6,1,9,2};
    selection(0,arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}