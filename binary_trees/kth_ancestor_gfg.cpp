Node* solve(Node *root, int &k, int node){
    //base case
    if(!root){
        return NULL;
    }
    if(root -> data == node){
        return root;
    }
    
    //same as lca
    Node* leftAns = solve(root -> left,k,node);
    Node* rightAns = solve(root -> right,k,node);
    
    //wapas jab jaoege
    //now if leftans and rightans one is not null return that otherwise both null return null.
    if(leftAns != NULL && rightAns == NULL){
        //first decrement k value anad then check if it is equal to 0
        k--;
        if(k <= 0){
            //answer lock karne ke liye ki aage kabhi bhi change n ho kyunki k<=0 ban chuka hai.
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL){
        //first decrement k value anad then check if it is equal to 0
        k--;
        if(k <= 0){
            //answer lock karne ke liye ki aage kabhi bhi change n ho kyunki k<=0 ban chuka hai.
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    //agar dono hi NULL hai.
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node* ans = solve(root,k,node);
    //ab check karo ki null hai kya jo answer aaya hai
    //bahut imp edge case ye hai ki agar root node hi given node ke equal hai to return -1.
    if(ans == NULL || ans -> data == node){
        return -1;
    }
    else{
        return ans -> data;
    }
}