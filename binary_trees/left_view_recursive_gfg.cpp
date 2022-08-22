void solve(Node* root,vector<int> &ans,int level){
    //base case
    if(root == NULL){
        return;
    }
    
    //check if it entered new level.
    if(ans.size() == level){
        ans.push_back(root -> data);
    }
    
    //recursive call;
    solve(root -> left,ans,level+1);
    //right call if left call reaches NULL .
    solve(root -> right,ans,level+1);
    
}

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   solve(root,ans,0);
   return ans;
}