//unotimized approach o(n^2) since we are calling height also.
class Solution {
  private:
    int height(Node* root){
        //base case
        if(root == NULL){
            return 0;
        }
        //height of the left part.
        int left = height(root -> left);
        //height of the right part.
        int right = height(root -> right);
        
        return max(left,right)+1;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        //base case
        if(root == NULL){
         return 0;
        }
        //means answer lies within left part.
        int opt1 = diameter(root -> left);
        //means answer lies within right part.
        int opt2 = diameter(root -> right);
        //means answer lies between left and right so we ned to simply calculate height.
        int opt3 = height(root -> left) + height(root -> right) + 1;
        
        //max of three will be the answer.
        int ans = max(opt1,max(opt2,opt3));
        return ans;
    }
};

//approach 2 - optimized
public:
    pair<int,int> Fastdiameter(Node* root){
        //base case and first will be left and second will be right.
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = Fastdiameter(root -> left);
        pair<int,int> right = Fastdiameter(root -> right);
        
        //option 1 will be diameter will be in left part.
        int opt1 = left.first;
        //option 2 will be diameter will be in right part.
        int opt2 = right.first;
        //option 3 will be the height of left and right + 1 will be diameter.
        int opt3 = left.second + right.second + 1;
        
        pair<int,int> ans;
        //for diameter
        ans.first = max(opt1,max(opt2,opt3));
        //for height.
        ans.second = max(left.second,right.second) + 1;
        return ans;
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        //first will be diameter.
        return Fastdiameter(root).first;
    }