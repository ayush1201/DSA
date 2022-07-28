void insertAtBottom(stack<int> &s,int ele){
    //base case
    if(s.empty()){
        s.push(ele);
        return;
    }
    
    int val = s.top();
    s.pop();
    
    //recursive call
    insertAtBottom(s,ele);
    s.push(val);
}
void reverseStack(stack<int> &stack) {
    // Write your code here
    //base case.
    if(stack.empty())
        return;
    
    int num = stack.top();
    stack.pop();
    
    //recursive call
    reverseStack(stack);
    
    insertAtBottom(stack,num);
    //return karte time nikala hua wapas dalte jaao.
}