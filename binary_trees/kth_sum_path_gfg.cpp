public:
  //the main concept is just use vector for storing every node val and traverse left and right and check at the end if there exists sum == k in  vector , if yes count increment and while returning backtrack.
    void solve(Node *root,int k,vector<int> &path,int &count){
        //base case
        if(!root){
            return;
        }
        
        //processing
        path.push_back(root -> data);
        //count increment while backtrack
        solve(root -> left,k,path,count);
        //right call
        solve(root -> right,k,path,count);
        
        //checking for the sum equal to k.
        int size = path.size();
        int sum=0;
        for(int i=size-1;i>=0;i--){
            sum+=path[i];
            if(sum == k){
                count++;
            }
        }
        path.pop_back();
    }
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> path;
        int count=0;
        solve(root,k,path,count);
        return count;
    }