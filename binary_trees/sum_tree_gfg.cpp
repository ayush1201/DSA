public:
    
    pair<bool,int> kyaSumHai(Node* root){
        //base case
        if(!root){
           pair<bool,int> p = make_pair(true,0);
           return p;
        }
        
        if(root -> left == NULL && root -> right == NULL){
            pair<bool,int> p = make_pair(true,root -> data);
            return p;
        }
        
        pair<bool,int> leftAns = kyaSumHai(root -> left);
        pair<bool,int> rightAns = kyaSumHai(root -> right);
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        bool cond = root -> data == (leftAns.second + rightAns.second);
        
        pair<bool,int> ans;
        if(left && right && cond){
            ans.first = true;
            //simple logic we have to get - root -> data + leftAns.second + rightAns.second = 2*(root->data).
            ans.second = 2*(root -> data);
        }
        else{
            ans.first = false;
            //iss case me sum se matlab nhi kyunki false hi aagya.
        }
        return ans;
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         return kyaSumHai(root).first;
         
    }