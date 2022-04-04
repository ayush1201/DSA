#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int N){
     for(int i=1;i<N;i++){
         int current=arr[i];
         int prev=i-1;
         while(prev>=0&&(arr[prev]>current)){
             arr[prev+1]=arr[prev];
             prev=prev-1;

         }
         arr[prev]=current;
     }
}





int main(){
    int arr[] ={5,4,1,2,3};
    int N=sizeof(arr)/sizeof(int);
    insertion_sort(arr,N);
    for(int i=0;i<N;i++){
        cout<<arr[i];
    }
return 0;
    }