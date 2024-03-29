#include <bits/stdc++.h> 
void heapify(vector<int> &arr,int n,int i){
    //since 0 th based indexing
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left < n && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }
    
    if(i != smallest){
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
    //n/2-1 is taken as n/2 to n are leaf nodes and all leaves are heaps.
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    return arr;
}
