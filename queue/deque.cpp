#include<iostream>
using namespace std;
#include<queue>

int main(){
    deque<int> d;

    d.push_front(12);
    d.push_back(13);
    d.push_front(15);
    d.push_back(16);
    d.pop_front();

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    return 0;

}