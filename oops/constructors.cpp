#include<iostream>
using namespace std;

class Hero{
    int health;
    public:
    char level;
    //paramterized constructor.
    Hero(int health,char level){
        cout<<"parameterized constructor called "<<endl;
        this->health=health;
        this->level=level;
    }
    //getter and setter are used to access private members outside of the class.
    int gethealth(){
        return health;
    }
    void sethealth(int health){
        this->health=health;
    }
};

int main(){
    Hero ram(20,'A');
    ram.sethealth(50);
    cout<<"health is "<<ram.gethealth()<<endl;


    return 0;
}