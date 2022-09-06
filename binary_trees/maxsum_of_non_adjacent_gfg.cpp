class Solution{
  public:
    //function to return pair in which first element is including that node with max sum and second is excluding that node and max sum.
    pair<int,int> solve(Node* root){
        //base case
        if(!root){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        //left and right ans call
        pair<int,int> leftAns = solve(root -> left);
        //call for right ans.
        pair<int,int> rightAns = solve(root -> right);
        //resultant pair which returns final ans.
        pair<int,int> res;
        
        //res ke first me include karenge root node ko,left ke exlcude aur right ke exlude ko add karenge.
        res.first = root -> data + leftAns.second + rightAns.second;
        //res ke second me option hai ki yato left ko include,exlude karo + ya right ko include,exclude karo.  
        res.second = max(leftAns.first,leftAns.second) + max(rightAns.first,rightAns.second);
        return res;
    }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int,int> ans = solve(root);
        return max(ans.first,ans.second);
    }
};