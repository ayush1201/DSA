#include <bits/stdc++.h> 
class node{
    public:
     int data;
     int i;
     int j;
     //constructor.
     node(int data,int row,int col){
         this -> data = data;
         i = row;
         j = col;
     }
};
class compare{
    public:
     //to create min heap.
     bool operator()(node* a,node* b){
         return a -> data > b -> data;
     }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node*,vector<node*>,compare> min_pq;
    
    //step 1 - store all first elements in pq.
    for(int i=0;i<k;i++){
        //creating node for karrays.
        node* tmp = new node(kArrays[i][0],i,0);
        min_pq.push(tmp);
    }
    
    //step 2 - now store pq.top() in variable and pop and insert i+1th element of same array.
    vector<int> ans;
    while(!min_pq.size()){
        node* temp = min_pq.top();
        ans.push_back(temp -> data);
        min_pq.pop();
        
        int i = temp -> i;
        int j = temp -> j;
        
        if(j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1],i,j+1);
            min_pq.push(next);
        }
    }
    return ans;
}
