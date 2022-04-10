#include<iostream>
using namespace std;

int binary_search(int arr[],int n,int key){
     int start=0;
     int end=n-1;
     int mid=start+(end-start)/2;      //to optimize code since when start and end will be than 2^31-1 then it will show out of range.
     while(start<=end){
         if(arr[mid]==key){
             return mid;
         }
         if(arr[mid]<key){
             start=mid+1;
         }
         else{
             end=mid-1;
         }
         mid=start+(end-start)/2;
     }
     return -1;
}

int main(){
   
     int odd[5]={2,3,7,10,20};
     int even[6]={2,3,7,10,20,25};

    int o=binary_search(odd,5,7);
     cout<<" the element is at "<<o<<endl;

     int e=binary_search(even,6,3);
     cout<<" the element is at "<<e;
     return 0;
}