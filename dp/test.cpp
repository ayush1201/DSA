#include<bits/stdc++.h>
using namespace std;

int solve(int i,int j1,int j2,int m,int n,vector<vector<int>> &mat, vector<vector<vector<int>>> &dp){
    //base case
    if(j1 < 0 || j1 >= n || j2 < 0 || j2 >= n){
        return -1e8;
    }
    if(i == m-1){
        if(j1 == 0 && j2 == n-1){
            return mat[i][j1] + mat[i][j2];
        }
        else{
            return -1e8;
        }
    }

    if(dp[i][j1][j2] != -1){
        return dp[i][j1][j2];
    }

    //recursive calls
    int maxi = -1e8;
    for(int dj1=-1;dj1<2;dj1++){
        for(int dj2=-1;dj2<2;dj2++){
            //9 states.
            int values = 0;
            if(j1 == j2){
                values += mat[i][j1];
            }
            else{
                values += mat[i][j1] + mat[i][j2];
            }
            values += solve(i+1,j1+dj1,j2+dj2,m,n,mat,dp);
            maxi = max(maxi,values);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> mat(m,vector<int> (n,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    vector<vector<vector<int>>> dp(r,vector<vector<int>> (c,vector<int> (c,-1)));
    return solve(0,0,n-1,m,n,mat,dp);
}