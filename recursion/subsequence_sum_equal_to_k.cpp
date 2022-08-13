#include<iostream>
#include<vector>
using namespace std;
//for getting first subsequence of the array as equal to given sum.

bool subseq(int index,vector<int> &ans,int *arr,int n,int sum,int tot){
    //base case
    if(index>=n){
        if(tot == sum){
            for(auto i : ans){
            cout<<i<<" ";
           }cout<<endl;
           return true;
        } 
        else {
            return false;
        }
    }

    //take the index number
    ans.push_back(arr[index]);
    //updating tot.
    tot += arr[index];
    //recursive call
    if(subseq(index+1,ans,arr,n,sum,tot) == true)
     return true;

    //don't take condition
    ans.pop_back();
    //removing last sum from tot.
    tot -= arr[index];
    //recursive call
    if(subseq(index+1,ans,arr,n,sum,tot) == true){
        return true;
    }
}



int main(){
    int arr[] = {1,2,1};
    int n = 3;
    int sum = 2;
    vector<int> ans;
    subseq(0,ans,arr,n,sum,0);
    return 0;
}