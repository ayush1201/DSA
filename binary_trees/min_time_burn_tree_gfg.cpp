//BFS approach.
class Solution {
  public:
    
    //function for parent mapping and getting target node.
    Node* parentMapping(Node* root,int target,map<Node*,Node*> &mpToParent){
        //level order traversal or BFS for mapping.
        queue<Node*> q;
        q.push(root);
        //since root has no baap.
        mpToParent[root] = NULL;
        Node* res = NULL;
        
        while(!q.empty()){
            Node* front = q.front();
            if(front -> data == target){
                res = front;
            }
            q.pop();
            
            if(front -> left){
                mpToParent[front -> left] = front;
                q.push(front -> left);
            }
            
            if(front -> right){
                mpToParent[front -> right] = front;
                q.push(front -> right);
            }
        }
        return res;
    }
    
    //visiting node function.
    int burnTime(Node* tgt,map<Node*,Node*> &mpToParent,int &time){
        map<Node*,bool> visited;
        queue<Node*> q;
        //first push target node.
        q.push(tgt);
        //initial target node visited because it is burnt at 0sec.
        visited[tgt] = true;
        
        while(!q.empty()){
            
            //we have to run loop according to size as left,right and parent nodes have to burn simultaneously.
            int size = q.size();
            //if any new changes are there in queue we have to increment time.
            int addedNewToQueue = 0;
            for(int i=0;i<size;i++){
                Node* front = q.front();
                q.pop();
                
                //for left child check visited or not.
                if(front -> left && !visited[front -> left]){
                    visited[front -> left] = true;
                    addedNewToQueue = 1;
                    q.push(front -> left);
                }
                //for right child check visited or not.
                if(front -> right && !visited[front -> right]){
                    visited[front -> right] = true;
                    addedNewToQueue = 1;
                    q.push(front -> right);
                }
                //for checking parent visited or not.
                if(mpToParent[front] && !visited[mpToParent[front]]){
                    visited[mpToParent[front]] = true;
                    addedNewToQueue = 1;
                    q.push(mpToParent[front]);
                }
            }
            if(addedNewToQueue){
                time++;
            }
        }
        return time;
    }
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        //algo :
        //step 1: create parent mapping
        //step 2: get target node.
        //step 3: check if visited and if queue appended increment time.
        
        map<Node*,Node*> mpToParent;
        int time = 0;
        //do the mapping of child with parent and gets the target node.
        Node* tgt = parentMapping(root,target,mpToParent);
        //this will go to every node and check if not visited add to queue and time increment.
        int ans = burnTime(tgt,mpToParent,time);
        return ans;
    }
};