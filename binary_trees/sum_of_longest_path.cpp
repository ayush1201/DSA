public:

    void solve(Node* root,int sum,int len,int &maxlen, int &ans){
        //base condition
        if(root == NULL){
            if(len > maxlen){
                maxlen = len;
                ans = sum;
            }
            if(len == maxlen){
                ans = max(ans,sum);
            }
            return;
        }
        sum = sum + root -> data;
        //left function call
        solve(root -> left,sum,len+1,maxlen,ans);
        //right function call
        solve(root -> right,sum,len+1,maxlen,ans);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        //agar tree empty hai
        if(!root){
            return 0;
        }
        
        int sum=0;
        int len=0;
        int maxlen=INT_MIN;
        int ans=INT_MIN;
        solve(root,sum,len,maxlen,ans);
        return ans;
    }