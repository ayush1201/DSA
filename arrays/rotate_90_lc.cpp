class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int srow=0;
        int erow=rows-1;
        int scol=0;
        int ecol=cols-1;
        int start=0;
        int end=cols-1;
        //first of all take transpose
        for(int i=0;i<rows;i++){
            for(int j=0;j<=i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
       // reverse matrix by 2 pointer approach
        while(start<end){
            for(int i=0;i<rows;i++){
                swap(matrix[i][start],matrix[i][end]);
            }
            start++;
            end--;
        }
        
    }
};