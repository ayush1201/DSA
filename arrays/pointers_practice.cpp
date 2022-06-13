#include<iostream>
using namespace std;

void display(int *p){
    cout<<"the value of pointer is : "<<p<<endl;
}



int main()
{
   int a=6;
   int *p=&a;
   display(p);
   return 0;

}