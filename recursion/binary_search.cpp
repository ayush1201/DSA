#include<iostream>
using namespace std;
bool binarysearch(int arr[],int start,int end,int key){
//base case if start becomes greater than end or if element is found.
//element not found.  
    if(start>end){
        return false;
    }
    int mid=start+(end-start)/2;
 //element found.   
    if(arr[mid]==key)
    return true;
    if(arr[mid]<key){
        return binarysearch(arr,mid+1,end,key);
    }
    else{
        return binarysearch(arr,start,mid-1,key);
    }

}


int main(){
    int arr[6]={1,2,3,5,6,8};
    bool ans=binarysearch(arr,0,5,1);

    if(ans){
        cout<<" the element is found :"<<endl;
    }
    else{
        cout<<" the element is not found :"<<endl;
    }
    return 0;
}