class Solution{
    private:
    bool issafe(vector<vector<int>> &m,vector<vector<int>> checkpath,int x,int y,int n){
        if((x>=0 && x<n) && (y>=0 && y<n) && m[x][y]==1 && checkpath[x][y]==1){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(vector<vector<int>> &m,vector<vector<int>> checkpath,int x,int y,vector<string> &ans,string path,int n){
        //base case
        if(x==n-1&&y==n-1){
            ans.push_back(path);
            return;
        }
        
        checkpath[x][y]=1;
        //down check
        int newx=x+1;
        int newy=y;
        if(issafe(m,checkpath,newx,newy,n)){
            path.push_back('D');
            solve(m,checkpath,newx,newy,ans,path,n);
            path.pop_back();
        }
        //left check
        newx=x;
        newy=y-1;
        if(issafe(m,checkpath,newx,newy,n)){
            path.push_back('L');
            solve(m,checkpath,newx,newy,ans,path,n);
            path.pop_back();
        }
        //right check
        newx=x;
        newy=y+1;
        if(issafe(m,checkpath,newx,newy,n)){
            path.push_back('R');
            solve(m,checkpath,newx,newy,ans,path,n);
            path.pop_back();
        }
        //up check
        newx=x-1;
        newy=y;
        if(issafe(m,checkpath,newx,newy,n)){
            path.push_back('U');
            solve(m,checkpath,newx,newy,ans,path,n);
            path.pop_back();
        }
        
        //backtrack so that after this new path can be found.
        checkpath[x][y]=0;
        
        
    }
    public:
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==0){
            return ans;
        }
        //to check whether the next position is already reached earlier.
        vector<vector<int>> checkpath;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                checkpath[i][j]=0;
            }
        }
        int curx=0;
        int cury=0;
        string path="";
        solve(m,checkpath,curx,cury,ans,path,n);
        sort(ans.begin(),ans.end());
        return ans;
    }                               
};