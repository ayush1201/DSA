#include<iostream>
using namespace std;
bool linearsearch(int arr[],int size,int key){
//base case is if size is 0 or 1 by default is true.    
    if(size==0){
        return false;
    }

    if(arr[0]==key)
     return true;
    else{
        bool remaining_part=linearsearch(arr+1,size-1,key);
        return remaining_part;
    } 
}


int main(){
    int arr[6]={1,2,3,5,6,8};
    bool ans=linearsearch(arr,6,9);

    if(ans){
        cout<<" the element is found :"<<endl;
    }
    else{
        cout<<" the element is not found :"<<endl;
    }
    return 0;
}