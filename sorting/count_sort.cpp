#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

void count(int arr[],int N){
     int large=-1;
     for(int i=0;i<N;i++){
         large=max(large,arr[i]);
     }
    vector<int> count(large+1,0);
    for(int i=0;i<N;i++){
        count[arr[i]]++;
    }
    int j=0;
    for(int i=0;i<=large;i++){
        while(count[i]>0){
            arr[j]=i;
            count[i]--;
            j++;
        }
    }



}





int main(){
    int arr[] ={5,4,1,2,3};
    int N=sizeof(arr)/sizeof(int);
    count(arr,N);
    for(int i=0;i<N;i++){
        cout<<arr[i];
    }
return 0;
    }