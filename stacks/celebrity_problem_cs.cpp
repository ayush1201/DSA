//Algo is store all the elements in stack, then take out two topo element and store in two variables, and check condition that a know b or b know a.
//aur jab end me stack ka size 1 ho jaye to jo element bacha hai vo potential celebrity hai ,hir uspe condition lagao ki uski sari rows 0 ho aur column values 1.
class Solution 
{
    private:
    bool knows(vector<vector<int> > M,int a,int b){
        if(M[a][b]==1)
         return true;
        else
         return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s;
        //loop to enter all elements in stack.
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        //now check the top two numbers and who knows other.
        while(s.size()>1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            //check who knows other.
            if(knows(M,a,b)){
                s.push(b);
                //means a knows b then b can be celebrity so push to stack.
            }
            else{
                s.push(a);
            }
            
        }
        //single element will be left in stack which can be celebrity.
        //check for rows and column condition.
        int candidate = s.top();
        int zeroCount=0;
        
        for(int i=0;i<n;i++){
            if(M[candidate][i]==0)
             zeroCount++;
        }
        if(zeroCount != n){
            return -1;
        }
        
        //to check for column values of candidate
        
        int oneCount = 0;
        
        for(int i=0;i<n;i++){
            if(M[i][candidate] == 1){
                oneCount++;
            }
        }
        if(oneCount != n-1){
            return -1;
        }
        
        return candidate;
    }
}