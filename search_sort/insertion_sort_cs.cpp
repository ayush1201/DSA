#include<bits/stdc++.h>
using namespace std;

void insertionSort(int n, vector<int> &arr){
    // Write your code here.
	for(int i=1;i<n;i++){   //we assume that element at 0th index is already sorted.
		int temp=arr[i];
		int j=i-1;
		for(;j>=0;j--){
			if(temp<arr[j])
				arr[j+1]=arr[j];
			else{
				break;
			}
		}
		arr[j+1]=temp;
	}
}