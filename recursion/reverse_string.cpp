//Two ways of passing string is pass by reference then also changes will be copied to main string and other one is returning the 
//changed string to a variable as done here.
#include<iostream>
using namespace std;

string reverse(int start,int end,string s){
    //base case 
    if(start>end){
        return s;
    }
    //processing
    swap(s[start],s[end]);
    start++;
    end--;
    //recursive relation
    return reverse(start,end,s);

}


int main(){
    string s="babbar";
    int start=0;
    int end=s.length()-1;
    int len=s.length();
    string ans=reverse(start,end,s);
    cout<<" the reversed sring is : "<<ans<<endl;
    return 0;
}