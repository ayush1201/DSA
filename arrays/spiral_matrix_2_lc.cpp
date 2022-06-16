//Similar as spiral matrix 1 we have to thinkk in four different directions and the only catch is how to generate vector with given size.
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int ele=1;
        vector<vector<int>> ans(n, vector<int> (n));
        int row=n;
        int col=n;
        int srow=0;
        int scol=0;
        int erow=row-1;
        int ecol=col-1;
        int tot=row*col;
        
        while(ele<=tot){
            for(int i=scol;ele<=tot&&i<=ecol;i++){
                ans[srow][i]=ele++;
            
            }
            srow++;
            for(int j=srow;ele<=tot&&j<=erow;j++){
                ans[j][ecol]=ele++;
               
            }
            ecol--;
            for(int i=ecol;ele<=tot&&i>=scol;i--){
                ans[erow][i]=ele++;
               
            }
            erow--;
            for(int j=erow;ele<=tot&&j>=srow;j--){
                ans[j][scol]=ele++;
                
            }
            scol++;
        }
        return ans;
    }
};