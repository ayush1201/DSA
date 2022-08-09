// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> s;
    int n = q.size();
    //step1: get all elements till k and put in stack .
    for(int i=0;i<k;i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    //step2: now pop values from stack and push in queue which will be pushed in reverse order.
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }
    //step3: now first (n-k) elements remove from start and push it to end.
    for(int i=0;i<(n-k);i++){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}