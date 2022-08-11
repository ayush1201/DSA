#include<iostream>
using namespace std;

class kQueue{

    public:
       int n;
       int k;
       int *arr;
       int *front;
       int *rear;
       int *next;
       int freeSpot;

    public:
       kQueue(int n,int k){
        this -> n = n;
        this -> k = k;
        front = new int[k];
        rear = new int[k];
        for(int i=0;i<k;i++){
            front[i]=-1;
            rear[i]=-1;
        }

        next = new int[n];
        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;
        arr = new int[n];
        freeSpot = 0;

       }   

       void enqueue(int data,int qn){
        //checking overflow
        if(freeSpot == -1){
            return;
        }
        
        //get the first free index where you can insert
        int index = freeSpot;

        //update freeSpot
        freeSpot = next[index];

        //check whether first element
        if(front[qn-1] == -1){
            front[qn-1] = index;
        }
        else{
            //link current element to previous rear
            next[rear[qn-1]] = index;
        }

        //update next.
        next[index] = -1;

        //rear update since it is queue.
        rear[qn-1] = index;

        //push element
        arr[index] = data;
       }

       int dequeue(int qn){
        //check for underflow
        if(front[qn-1] == -1){
            cout<<"queue is empty "<<endl;
            return -1;
        }
        //find index to pop 
        int index = front[qn-1];

        //front aage badao
        front[qn-1] = next[index];

        //freeslots ko manage karo
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
       }
};

int main(){

    kQueue q(10,3);
    q.enqueue(10,1);
    q.enqueue(20,1);
    q.enqueue(30,2);
    q.enqueue(25,1);

    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    return 0;
}