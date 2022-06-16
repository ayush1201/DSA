#include<iostream>
using namespace std;


int main(){
    int m=3;
    
    int** arr=new int*[m];

    for(int i=0;i<m;i++){
        //int cols;
        arr[i]=new int[i+1];
    }
//entering numbers 
cout<<"entering elements :"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<i+1;j++){
            cin>>arr[i][j];
        }
    }

//displaying the entered matrix
cout<<"displaying elements :"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<i+1;j++){
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