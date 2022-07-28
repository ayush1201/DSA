void solve(stack<int>& s,int num){
    //base case 
    if(s.empty()){
        s.push(num);
        return;
    }
    
    int val = s.top();
    s.pop();
    
    //recursive call
    solve(s,num);
    //in the end wapas jo val hai dalte jana return ke wakt.
    s.push(val);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack,x);
    return myStack;
}