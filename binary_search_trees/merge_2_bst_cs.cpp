//approach 1
//algo get 2 inorder of the both trees and then merge both inorders .Then simply call inorder to bst function and make tree from merged inorder.

void getInorder(TreeNode<int> *root,vector<int> &inorder){
    //base case
    if(!root){
        return;
    }
    
    //left call
    getInorder(root -> left,inorder);
    //add in inorder
    inorder.push_back(root -> data);
    //right call
    getInorder(root -> right,inorder);
}

vector<int> mergeInorders(vector<int> &inorder1,vector<int> &inorder2){
    vector<int> mergedinorder(inorder1.size() + inorder2.size());
    int i = 0,j = 0,k = 0;
    
    while(i < inorder1.size() && j < inorder2.size()){
        if(inorder1[i] < inorder2[j]){
            mergedinorder[k++] = inorder1[i++];
        }
        else{
            mergedinorder[k++] = inorder2[j++];
        }
    }
    //if inorder1 finished earlier.
    while(j < inorder2.size()){
            mergedinorder[k++] = inorder2[j++];
        }
    //if inorder2 finished earlier
    while(i < inorder1.size()){
            mergedinorder[k++] = inorder1[i++];
        }
    return mergedinorder;
}

TreeNode<int> *inorderToBST(vector<int> &mi,int s,int e){
    //base case
    if(s > e){
        return NULL;
    }
    
    int mid = (s+e)/2;
    //initialising root node for mid value.
    TreeNode<int> *root = new TreeNode<int>(mi[mid]);
    
    root -> left = inorderToBST(mi,s,mid-1);
    root -> right = inorderToBST(mi,mid+1,e);
    
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    vector<int> inorder1;
    vector<int> inorder2;
    //vector<int> mergedinorder();
    
    //for inorder 1
    getInorder(root1,inorder1);
    //for inorder 2
    getInorder(root2,inorder2);
    
    //now merge both vectors.
    vector<int> mergeinorder = mergeInorders(inorder1,inorder2);
    
    //now make tree from mergedinorder.
    return inorderToBST(mergeinorder,0,mergeinorder.size()-1);
    
}