//concept is use inorder property and store elements in vector of type node. Then traverse in the vector and left of every node pointing to NULL and right to next pointer.

void inorderTraversal(TreeNode<int>* root,vector<int> &inorder){
    //base case
    if(!root){
        return;
    }
    
    inorderTraversal(root -> left,inorder);
    inorder.push_back(root -> data);
    inorderTraversal(root -> right,inorder);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    //1st step
    vector<int> inorder;
    inorderTraversal(root,inorder);
    int n = inorder.size();
    TreeNode<int>* newroot = new TreeNode<int>(inorder[0]);
    TreeNode<int>* curr = newroot;
    //2nd step
    for(int i=1;i<n;i++){
        TreeNode<int>* temp = new TreeNode<int>(inorder[i]);
        curr -> left = NULL;
        curr -> right = temp;
        curr = temp;
        
    }
    //3rd step
    //now for last node make left and right both to null.
    //curr is at last
    curr -> left = NULL;
    curr -> right = NULL;
    return newroot;
}