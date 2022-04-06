#include<iostream>
#include<string>
using namespace std;

int main(){
   

   int alph=0;
   int num=0;
   int space=0;
   char ch=cin.get();
   while(ch!='\n'){
       if(ch>='0' && ch<='9')
       num++;

       if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
       alph++;

       if(ch==' ')
       space++;

       ch=cin.get();
   }

   cout<<num<<endl;
   cout<<alph<<endl;
   cout<<space;
return 0;
}