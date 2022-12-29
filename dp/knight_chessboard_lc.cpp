//simple do dp array banao aur jitne moves hai har bar jaha jaa sakta hai knight 1/8 se multiply karke add kardo aur end me sabka sum lelo .
class Solution {
public:
    bool isPossible(int i,int j,int n){
        if(i >=0 && j >=0 && i < n && j < n){
            return true;
        }
        else{
            return false;
        }
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> curr(n,vector<double> (n,0));
        vector<vector<double>> next(n,vector<double> (n,0));

        curr[row][column] = 1;
        for(int chance=1;chance<=k;chance++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(curr[i][j] != 0){
                        int ni = 0;
                        int nj = 0;

                        ni = i-1;
                        nj = j-2;
                        if(isPossible(ni,nj,n)){
                            next[ni][nj] += curr[i][j]/8.0;
                        }

                        ni = i-2;
                        nj = j-1;
                        if(isPossible(ni,nj,n)){
                            next[ni][nj] += curr[i][j]/8.0;
                        }

                        ni = i-1;
                        nj = j+2;
                        if(isPossible(ni,nj,n)){
                            next[ni][nj] += curr[i][j]/8.0;
                        }

                        ni = i-2;
                        nj = j+1;
                        if(isPossible(ni,nj,n)){
                            next[ni][nj] += curr[i][j]/8.0;
                        }

                        ni = i+1;
                        nj = j-2;
                        if(isPossible(ni,nj,n)){
                            next[ni][nj] += curr[i][j]/8.0;
                        }

                        ni = i+2;
                        nj = j-1;
                        if(isPossible(ni,nj,n)){
                            next[ni][nj] += curr[i][j]/8.0;
                        }

                        ni = i+1;
                        nj = j+2;
                        if(isPossible(ni,nj,n)){
                            next[ni][nj] += curr[i][j]/8.0;
                        }

                        ni = i+2;
                        nj = j+1;
                        if(isPossible(ni,nj,n)){
                            next[ni][nj] += curr[i][j]/8.0;
                        }                        
                    }
                }
            }
            curr = next;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    next[i][j] = 0;
                }
            }
        }

        double prob = 0.0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                prob += curr[i][j];
            }
        }

        return prob;
    }
};