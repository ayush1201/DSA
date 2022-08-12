#include<iostream>
#include<vector>
using namespace std;

void subseq(int index,vector<int> &ans,int *arr,int n){
    //base case
    if(index>=n){
        for(auto i : ans){
            cout<<i<<" ";
        }cout<<endl;
        return;
    }

    //take the index number
    ans.push_back(arr[index]);
    //recursive call
    subseq(index+1,ans,arr,n);

    //don't take condition
    ans.pop_back();
    //recursive call
    subseq(index+1,ans,arr,n);
}



int main(){
    int arr[] = {3,1,2};
    int n = 3;
    vector<int> ans;
    subseq(0,ans,arr,n);
    return 0;
}