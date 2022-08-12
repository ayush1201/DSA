#include<iostream>
using namespace std;



void reverse(int *arr,int i,int n){
    //base codition
    if(i>=n/2){
        return;
    }

    //processing
    swap(arr[i],arr[n-i-1]);

    reverse(arr,i+1,n);
}


int main(){
    int arr[7] = {2,3,1,5,6,8,4};
    reverse(arr,0,7);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}