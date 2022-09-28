#include <bits/stdc++.h> 

void addValues(vector<vector<int>> &board,vector<vector<int>> &ans,int n){
    vector<int> res;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res.push_back(board[i][j]);
        }
    }
    ans.push_back(res);
}

bool isSafe(int row,int col,vector<vector<int>> &board,vector<vector<int>> &ans,int n){
    //check three conditions in same row no queen shuld be there, in left upper diagonal no queen  should be there and so in left below diagonal,no need to check the col.
    int x = row;
    int y = col;
    
    //check for row.
    while(y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        y--;
    }
    
    //check for left upper diagonal.
    x = row;
    y = col;
    while(x >= 0 && y >=0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }
    
    //check for left below diagonal.
    x = row;
    y = col;
    while(x < n && y >=0){
        if(board[x][y] == 1){
            return false;
        }
        x++;
        y--;
    }
    //means it is safe to place queen at this place.
    return true;
}

void solve(int col,vector<vector<int>> &ans,vector<vector<int>> &board,int n){
    //base case when all cols are reached traversal.
    if(col == n){
        //add the board values to ans,.
        addValues(board,ans,n);
        return;
    }
    
    //agar base case nhi hai to aage processing ke liye queen dekho.
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,ans,n)){
            //agar safe hai to queen laga do.
            board[row][col] = 1;
        
        solve(col+1,ans,board,n);
        //ab wapas aao to queen hata do.
        board[row][col] = 0;
        }
    }
 
    
}

vector<vector<int>> nQueens(int n)
{
	// Write your code here
    //making 2 d array of board.
    //initially marking all board unmarked.
    vector<vector<int>> board(n,vector<int> (n,0));
	vector<vector<int>> ans;
    
    //starting from col 0.
    solve(0,ans,board,n);
    return ans;
}