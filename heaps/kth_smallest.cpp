class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        //step 1 copy first k elements in pq.
        priority_queue<int> pq;
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        
        //step 2 now from k to n-1 just check for every element whether it is smallest than pq.top
        for(int i=k;i<=r;i++){
            int ele = arr[i];
            if(pq.top() > ele){
                pq.pop();
                pq.push(ele);
            }
        }
        
        //now the remaining queue is just containing k elements from which the top will be kth smallest.
        int kth = pq.top();
        return kth;
    }
};