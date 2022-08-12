#include<iostream>
using namespace std;

void reversePrint(int i,int n){
    //basse case
    if(i>n)
     return;

    
    reversePrint(i+1,n);
    //while coming back this will be executing. 
    cout<<i<<endl;
}

int main(){
    int n;
    cout<<"enter the number :"<<endl;
    cin>>n;

    reversePrint(1,n);
    return 0;

}