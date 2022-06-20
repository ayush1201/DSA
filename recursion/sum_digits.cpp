#include<iostream>
using namespace std;
int sum(int arr[],int size){
//base case is if size is 0 or 1 by default is true.    
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    int remaining_part=sum(arr+1,size-1);
    int sum = arr[0]+remaining_part;
    return sum;
}


int main(){
    int arr[6]={1,2,3,4,5};
    int ans=sum(arr,5);
    cout<<"the sum of array is :"<<ans<<endl;
    return 0;
}