#include<iostream>
using namespace std;

bool checkpalin(int start,int end,string& s){
    cout<<s<<endl;
    //base case 
    if(start>end){
        return true;
    }
    if(s[start]!=s[end])
     return false;
    else{
        start++;
        end--;
    //recursive relation
    checkpalin(start,end,s);
    
    }

}


int main(){
    string s="babbab";
    int start=0;
    int end=s.length()-1;
    bool palin=checkpalin(start,end,s);
    if(palin){
        cout<<"it is palindrome :"<<endl;
    }
    else{
        cout<<"not a palindrome :"<<endl;
    }
    return 0;
}