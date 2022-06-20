#include<iostream>
using namespace std;

void say_dig(int n,string arr[]){
//base case
     if(n==0)
      return;
     
//processing part
     int dig=n%10;
     n=n/10;
       
//recursive relation is print rest of n.
     say_dig(n,arr);
     cout<<arr[dig]<<" ";
}



int main(){
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cout<<"enter the number : "<<endl;
    cin>>n;
    say_dig(n,arr);
    return 0;
}