Node* solve(int in[],int post[],int n,int &index,unordered_map<int,int> &nodeInsert,int ins,int ine){
    //base case
    if(ins > ine || index < 0){
        return NULL;
    }
    
    //put the index element which is first in root and decrement index till 0.
    int element = post[index--];
    Node* root = new Node(element);
    
    //finding index in inorder.
    int pos = nodeInsert[element];
    //left and right calls
    root -> right = solve(in,post,n,index,nodeInsert,pos+1,ine);
    root -> left = solve(in,post,n,index,nodeInsert,ins,pos-1);
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    //for storing the indices and particular element of inorder to save time.
    unordered_map<int,int> nodeInsert;
    for(int i=0;i<n;i++){
        nodeInsert[in[i]] = i;
    }
    int postIndex = n-1;
    Node* ans = solve(in,post,n,postIndex,nodeInsert,0,n-1);
    return ans;
}