vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> ans;
   queue<Node*> q;

    if(!root){
      return ans;
    }
    q.push(root);
   
   //jabtak poori queue khali na ho jaye.
   while(!q.empty()){
       Node* temp = q.front();
       q.pop();
       
       //ye loop hai check karne ke liye ki temp -> right null na ho .
       while(temp){
           if(temp -> left)
           q.push(temp -> left);
           ans.push_back(temp -> data);
           temp = temp -> right;
       }
   }
   return ans;
}