#include<bits/stdc++.h>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
    priority_queue<int,vector<int>,greater<int>> pq;
    
    //get subarray sums.
    int n = arr.size();
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            //push pop in pq.
            if(pq.size() < k){
                pq.push(sum);
            }
            else{
                if(sum > pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}