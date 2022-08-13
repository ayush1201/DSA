//this one is modification of sunsequence equal to k and remember this in whole life that in this we will count in two different parts left and right.
#include<iostream>
#include<vector>
using namespace std;
//for getting first subsequence of the array as equal to given sum.

int subseq(int index,int *arr,int n,int sum,int tot){
    //base case
    if(index>=n){
        if(tot == sum){
            return 1;
        } 
        else {
            return 0;
        }
    }

    
    //updating tot.
    tot += arr[index];
    //recursive call
    int left = subseq(index+1,arr,n,sum,tot);

    //removing last sum from tot.
    tot -= arr[index];
    //recursive call
    int right = subseq(index+1,arr,n,sum,tot);

    return left + right;
}



int main(){
    int arr[] = {1,2,1};
    int n = 3;
    int sum = 2;
    cout<<subseq(0,arr,n,sum,0)<<endl;
    return 0;
}