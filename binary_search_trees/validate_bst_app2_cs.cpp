//approach 2 is that at every node check whether root -> data lies in the range passed, and if go left range is shifted and in right range is shifted.

bool isBST(BinaryTreeNode<int> *root,int minRange,int maxRange){
    //base case;
    if(root == NULL){
        return true;
       
    }
    if(root -> data >= minRange && root -> data <= maxRange){
        //check in both left and right subtrees if answer is correct.
        bool left = isBST(root -> left,minRange,root -> data);
        bool right = isBST(root -> right,root -> data,maxRange);
        return left && right;
    }
    else{
        return false;
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return isBST(root,INT_MIN,INT_MAX);
}