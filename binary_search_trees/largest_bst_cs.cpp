//optimized approach - is every node is valid bst ,check left subtree isvalid bst and right subtree is valid bst ,and finally check root -> data lies between maxleft and maxright. 
//use class for returning 4 values.
class info{
    public:
     int maxi;
     int mini;
     bool isBST;
     int size;
};

info solve(TreeNode<int>* root,int &ans){
    //base case
    if(!root){
        return {INT_MIN,INT_MAX,true,0};
    }
    //left call
    info left = solve(root -> left,ans);
    //right call
    info right = solve(root -> right,ans);
    
    //creating object currNode.
    info currNode;
    //3 variables are assigned.
    currNode.size = left.size + right.size + 1;
    currNode.mini = min(root -> data,left.mini);
    currNode.maxi = max(root -> data,right.maxi);
    //now to check condition for bst.
    
    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }
    //update ans or maxsize,update tabhi karna hai jab currNode bst ho.
    if(currNode.isBST){
        ans = max(ans,currNode.size);
    }
    return currNode;
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int maxsize = 0;
    info temp = solve(root,maxsize);
    return maxsize;
}