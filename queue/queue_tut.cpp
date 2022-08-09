#include<iostream>
#include<queue>
using namespace std;



int main(){
    queue<int> q;
    
    q.push(11);

    q.push(13);

    q.push(15);

    q.push(19);

    q.pop();

    cout<<q.front()<<endl;

    q.pop();
    q.pop();
    q.pop();

    if(q.empty()){
        cout<<"the queue is empty :"<<endl;
    }
    else{
        cout<<"the queue is not empty :"<<endl;
    }
    return 0;
}

