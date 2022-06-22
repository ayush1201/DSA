#include<iostream>
using namespace std;

void bubble(int arr[],int n){
    //base case
    if(n==0||n==1){
        return ;
    }
    //one case is solved which will put biggest element at last.
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    //recursive call
    bubble(arr,n-1);
}

int main(){
    int arr[5]={3,6,1,9,2};
    bubble(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}