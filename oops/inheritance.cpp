#include<iostream>
using namespace std;

class human{

    public:
    int age;
    int height;
    void setage(int age){
        this->age=age;
    }

    int getage(){
        return this->age;
    }
    

};

class male:public human{
    public:
    int hand;
};

int main(){

    male m1;
    cout<<m1.age<<endl;
    m1.setage(30);
    cout<<m1.age<<endl;
    cout<<m1.hand<<endl;
    return 0;
}