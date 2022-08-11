#include<iostream>
#include<queue>
using namespace std;

int solve(int* arr,int n,int k){
    //making 2 queues for minimum and maximum.
    queue<int> maxi;
    queue<int> mini;

    //addition of first window size
    for(int i=0;i<k;i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop();
        }
        maxi.push(i);
        mini.push(i);

    }
    int ans = 0;

    ans += arr[maxi.front()] + arr[mini.front()];

    //remaining windows compute in same way.
    for(int i=k;i<n;i++){
        //removal logic since window is shifting forward.
        while(!maxi.empty() && i-maxi.front() >= k){
            maxi.pop();
        }

        while(!mini.empty() && i-mini.front() >= k){
            mini.pop();
        }

        //addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop();
        }
        maxi.push(i);
        mini.push(i);
        
        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

int main(){
    int arr[7] = {2,-5,-1,7,-3,-1,-2};
    int k=4;

    cout<<solve(arr,7,k)<<endl;

    return 0;
}


