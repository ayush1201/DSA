vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    queue<long long int> q;
    vector<long long> ans;
    //step 1: store all the negative value indices from first k window in q.
    for(int i=0;i<K;i++){
        if(A[i]<0){
            q.push(i);
        }
    }
    //adding ans for first window.
    if(q.size()>0){
     ans.push_back(A[q.front()]);
    }
    else{
     ans.push_back(0);
    }
    //step 2: now from k+1 to N run loop again and now slide the window.
    //if i-first element of queue is >= k then remove first element of queue.
    //and for adding in queue check if arr[i]<0.
    
    //step 3: now side by side check that if size is not zero of queue then add q ka front element ka number in ans.
    //else add 0 in ans.
    
    for(int i=K;i<N;i++){
        if(!q.empty() && i-q.front()>=K){
            //for removing
            q.pop();
        }
        //for adding the negative number.
        if(A[i]<0){
            q.push(i);
        }
        if(q.size()>0){
         ans.push_back(A[q.front()]);
        }
        else{
         ans.push_back(0);
        }
    }
    return ans;                                             
 }