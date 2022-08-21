public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        //creating map for vertical order and level order and nodes in level order.
        map<int,map<int,vector<int>>> nodes;
        //making queue for level order traversal.
        queue<pair<Node*,pair<int,int>>> q;
        
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            
            pair<Node*,pair<int,int>> tmp = q.front();
            q.pop();
            Node* frontnode = tmp.first;
            //hd is horizontal distance and which is in pair<int,int>.first and lvl is level which is pair<int,int>.second. 
            int hd = tmp.second.first;
            int lvl = tmp.second.second;
            
            //inserting into map at hd,lvl
            nodes[hd][lvl].push_back(frontnode -> data);
            
            if(frontnode -> left){
                //pair type ka push karenge kyunki left jayenge to hd kam hoga aur lvl badega neeche jane pe.
                q.push(make_pair(frontnode -> left,make_pair(hd-1,lvl+1)));
            }
            if(frontnode -> right){
                //pair me pair push, hd increment by 1 and lvl will also increment by 1.
                q.push(make_pair(frontnode -> right,make_pair(hd+1,lvl+1)));
            }
        }
        //now traversing in map and printing according to hd.
        for(auto i:nodes){
            for(auto j:i.second){
                for(auto k:j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }