class Solution{
    public:
    
    void heapify(vector<int> &merged,int &i,int n){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left < n && merged[largest] < merged[left]){
            largest = left;
        }
        if(right < n && merged[largest] < merged[right]){
            largest = right;
        }
        
        //now check if largest is changed
        if(largest != i){
            swap(merged[largest],merged[i]);
            heapify(merged,largest,n);
        }
        return;
        
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        //step 1 - merge both arrays.
        vector<int> merged;
        //priority_queue<int> pq;
        for(auto i:a){
            merged.push_back(i);
        }
        for(auto i:b){
            merged.push_back(i);
        }
        
        //step 2 - now use heapify algo to make heap .
        int size = merged.size();
        //since it is zero based indexing.
        for(int i=size/2-1;i>=0;i--){
            heapify(merged,i,size);
        }
        return merged;
    }
};