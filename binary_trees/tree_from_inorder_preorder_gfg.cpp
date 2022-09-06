//algo - take index which is 0 of preorder in initial as root, and find root element in inorder array and create a root node and call root -> left me left of inorder and root -> right me right of indorder. Aisa karte jaao jab tak base condition na reach ho.
class Solution{
    public:
    
    int findPos(int in[],int pre[],int n,int element){
        for(int i=0;i<n;i++){
            if(in[i] == element){
                return i;
            }
        }
        return -1;
    }
    
    Node* solve(int in[],int pre[],int n,int &index,int start,int end){
        //base case
        if(index>=n || start > end){
            return NULL;
        }
        
        //find root and increment index for further roots.
        int element = pre[index++];
        //making root node for every element of preorder.
        Node* root = new Node(element);
        //find position of that element in inorder.
        int position = findPos(in,pre,n,element);
        
        //now left and right call.
        root -> left = solve(in,pre,n,index,start,position-1);
        
        root -> right = solve(in,pre,n,index,position+1,end);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex = 0;
        Node* ans = solve(in,pre,n,preOrderIndex,0,n-1);
        return ans;
        
    }
};