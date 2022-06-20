#include<iostream>
using namespace std;
bool issorted(int arr[],int size){
//base case is if size is 0 or 1 by default is true.    
    if(size==0||size==1){
        return true;
    }

    if(arr[0]>arr[1])
     return false;
    else{
        bool remaining_part=issorted(arr+1,size-1);
        return remaining_part;
    } 
}


int main(){
    int arr[6]={1,2,3,5,6,8};
    bool ans=issorted(arr,6);

    if(ans){
        cout<<" the array is sorted :"<<endl;
    }
    else{
        cout<<" the array is not sorted :"<<endl;
    }
    return 0;
}