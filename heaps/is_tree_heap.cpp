//check for two conditions if it is CBT or not and is it max heap or node by conparing parent nodes with child nodes.
class Solution {
  public:
  
    int countNode(struct Node* root){
        //base case
        if(!root){
            return 0;
        }
        
        int ans = 1 + countNode(root -> left) + countNode(root -> right);
        return ans;
    }
    
    bool isCBT(struct Node* root ,int i,int count){
        //base case
        if(!root){
            return true;
        }
        if(i >= count){
            return false;
        }
        
        //means the current node is CBT ,check for left and right.
        bool left = isCBT(root -> left,2*i+1,count);
        bool right = isCBT(root -> right,2*i+2,count);
        return (left && right);
    }
    
    bool ismaxHeap(struct Node* root){
        //base case
        //three situations are there whether root has no child ,1 child or both child.
        if(root -> left == NULL && root -> right == NULL){
            return true;
        }
        if(!(root -> right )){
            return (root -> data > root -> left -> data);
        }
        //means both child are there.
        else{
            bool left = ismaxHeap(root -> left);
            bool right = ismaxHeap(root -> right);
            return (left && right && (root -> left -> data < root -> data && root -> right -> data < root -> data));
        }
    }
    
    bool isHeap(struct Node* tree) {
        // code here
        int index = 0;
        //counting number of nodes.
        int totalCount = countNode(tree);
        if((isCBT(tree,index,totalCount) && ismaxHeap(tree))){
            return true;
        }
        else{
            return false;
        }
        
    }
};