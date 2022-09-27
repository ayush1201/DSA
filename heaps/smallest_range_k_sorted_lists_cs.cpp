#include<queue>
#include<bits/stdc++.h>
//creating node class
class node{
    public:
     int data;
     int row;
     int col;
    
     //constructor
     node(int d,int r,int c){
         data = d;
         row = r;
         col = c;
     }
};

//comparator class
class compare{
    public:
     bool operator()(node* a,node* b){
         return a -> data > b -> data;
     }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
    int mini = INT_MAX,maxi = INT_MIN;
    priority_queue<node*,vector<node*>,compare> pq;
    
    //pushing first elements of all lists in pq.
    for(int i=0;i<k;i++){
        int ele = a[i][0];
        //update maxi.
        mini = min(ele,mini);
        maxi = max(maxi,ele);
        pq.push(new node(ele,i,0));
    }
    int start = mini,end = maxi;
    while(!pq.empty()){
        node* temp = pq.top();
        pq.pop();
        
        mini = temp -> data;
        
        //range update
        if(maxi - mini < end - start){
            end = maxi;
            start = mini;
        }
        
        //check mini wali list ka agla exist karta hai 
        //max also updated if new element is max.
        if(temp -> col+1 < n){
            int row = temp -> row;
            int col = temp -> col;
            int ele = a[row][col+1];
            maxi = max(maxi,ele);
            pq.push(new node(ele,row,col+1));
        }
        else{
            //if list becomes empty
            break;
        }
        
        
    }
    return end-start+1;
}