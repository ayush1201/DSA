//Concept is just make recursion calls like this D,L,R,U and check whether is it safe to go there and if yes then just make that call and mark visited as true and then when it backtrack just unmark the visited.
#include <bits/stdc++.h> 

bool isSafe(int newx,int newy,vector < vector < int >> & arr,vector<vector<bool>> & visited,int n){
    if((newx>=0 && newx<n) && (newy>=0 && newy<n) && (arr[newx][newy] == 1) && (visited[newx][newy] == 0)){
        return true;
    }
    else{
        return false;
    }
}

void solve(int x,int y,vector < vector < int >> & arr,int n,vector<string> & ans,vector<vector<bool>> & visited,string res){
    //base case
    if(x == n-1 && y == n-1){
        //store the ansewr.
        ans.push_back(res);
        return;
    }
    
    visited[x][y] == 1;
    
    //check for D
    if(isSafe(x+1,y,arr,visited,n)){
        solve(x+1,y,arr,n,ans,visited,res + 'D');
        //while coming back make visited unmarked.
    }
    
    //check for L
    if(isSafe(x,y-1,arr,visited,n)){
        solve(x,y-1,arr,n,ans,visited,res + 'L');
        //while coming back make visited unmarked.
    }
    
    //check for R
    if(isSafe(x,y+1,arr,visited,n)){
        solve(x,y+1,arr,n,ans,visited,res + 'R');
        //while coming back make visited unmarked.
    }
    
    //check for U
    if(isSafe(x-1,y,arr,visited,n)){
        solve(x-1,y,arr,n,ans,visited,res + 'U');
        //while coming back make visited unmarked.
    }
    visited[x][y] == 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    //initially marking all visited as false;
    vector<vector<bool>> visited(n,vector<bool> (n,0)); 
    string res = "";
    //rat cannot start since starting is itself zero.
    if(arr[0][0] == 0){
        return ans;
    }
    //start at x,y coordinates.
    solve(0,0,arr,n,ans,visited,res);
    return ans;
}