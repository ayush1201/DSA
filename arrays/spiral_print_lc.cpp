class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int srow=0;
        int scol=0;
        int erow=row-1;
        int ecol=col-1;
        int tot=row*col;
        int count=0;
        
        while(count<tot){
            //printing first row
            for(int i=scol;count<tot&&i<=ecol;i++){
                ans.push_back(matrix[srow][i]);
                count++;
            }
            srow++;
            //printing last column
            for(int j=srow;count<tot&&j<=erow;j++){
                ans.push_back(matrix[j][ecol]);
                count++;
            }
            ecol--;
            //printing last row
            for(int i=ecol;count<tot&&i>=scol;i--){
                ans.push_back(matrix[erow][i]);
                count++;
            }
            //printing first column
            erow--;
            for(int j=erow;count<tot&&j>=srow;j--){
                ans.push_back(matrix[j][scol]);
                count++;
            }
            scol++;
        }
        return ans;
    }
};