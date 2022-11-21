#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    string filename,line;
    cin>>filename;
    //int siz = 100;
    
    string arr[100];
    int i=0;
    
    ifstream mfile(filename);
    if(mfile.is_open()){
        while(getline(mfile,line)){
            arr[i++] = line;
        }
        mfile.close();
    }
    else{
        cout<<"not open :"<<endl;
    }
    
    for(int j=0;j<i;j++){
        int k = 0;
        double sum = 0;
        while(k < arr[j].length()){
            if(arr[j][k] != ','){
                cout<<((arr[j][k] - '0')*2)<<endl;
            }
             
            k++;
        }
        //cout<<sum<<endl;
    }
    cout<<i<<endl;

    return 0;
}


