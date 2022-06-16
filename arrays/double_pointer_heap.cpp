#include<iostream>
using namespace std;


int main(){
    int m;
    cin>>m;
    int** arr=new int*[m];

    for(int i=0;i<m;i++){
        arr[i]=new int[m];
    }
//entering numbers 
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
//displaying the entered matrix
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
//deleting the memory allocated.
    for(int i=0;i<m;i++){
        delete [] arr[i];
    }   
    delete [] arr;
  return 0;
}