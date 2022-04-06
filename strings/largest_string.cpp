#include<iostream>
#include<string.h>
using namespace std;

int main(){
   
   char string[1000];
   char largest[1000];
   int large_len=0;


   int n;
   cin>>n;
   n=n+1;   //due to the fact that cin.getline() will be counting every nextline so we give extra count n=n+1
   while(n--){
       cin.getline(string,1000);
       int len=strlen(string);
       if(len>large_len){
           large_len=len;
           strcpy(largest,string);
       }

   }
   cout<<"the largest string is "<<largest;
   return 0;

}