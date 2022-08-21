//only catch in bottom view is that just simply add node->data corresponding to hd and don;t check whether it occurred previously.
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> bottomView(Node *root)
    {
        //Your code here
        map<int,int> topnode;
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
            
            Node* top = tmp.first;
            int hd = tmp.second;
            
            //don't check any condition and over write new values to that hd.
            topnode[hd] = top -> data;
            
            //now traversing left and right.
            if(top -> left){
                q.push(make_pair(top -> left,hd-1));
            }
            if(top -> right){
                q.push(make_pair(top -> right,hd+1));
            }
        }
        
        //now traverse in the map for printing the values seen from top.
        for(auto i:topnode){
            //i.second is basically the node->data value mapped at particular hd.
            ans.push_back(i.second);
        }
        return ans;
    }

};