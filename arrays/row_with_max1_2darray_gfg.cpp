class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int rows=arr.size();
	    int cols=arr[0].size();
	    int row=0;
	    int col=cols-1;
	    int count=0;
	    int maxi=0;
	    int ans=-1;
	    while((row<rows)&&(col>=0)){
	        if(arr[row][col]==1){
	           
	            count++;
	            if(maxi<count){
	                maxi=count;
	                ans=row;
	            }
	            col--;
	        }
	        else{
	            col=cols-1;
	            row++;
	            count=0;
	        }
	    }
	    return ans;
	}