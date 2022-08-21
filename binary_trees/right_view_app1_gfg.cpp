class Solution
{
    public:
    //concept is just do level order traversal same as left view and store level and particular first occurring val in map.
    //just don't check mp condition.
vector<int> rightView(Node *root)
    {
        //Your code here
        map<int,int> Leftnode;
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        
        queue<pair<Node*,int>> q;
        //adding first node in queue.
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            //phela node nikala queue ka joki pair type ka tha.
            pair<Node*,int> tmp = q.front();
            q.pop();
            
            Node* Left = tmp.first;
            int lvl = tmp.second;
            
            //don't check and overwrite last condition.
            
            Leftnode[lvl] = Left -> data;
            
            //now traversing left and right.
            if(Left -> left){
                q.push(make_pair(Left -> left,lvl+1));
            }
            if(Left -> right){
                q.push(make_pair(Left -> right,lvl+1));
            }
        }
        
        //now traverse in the map for printing the values seen from top.
        for(auto i:Leftnode){
            //i.second is basically the node->data value mapped at particular hd.
            ans.push_back(i.second);
        }
        return ans;
    }
};