//concept of next smallest element and prev smallest element.
//similar to next smaller and just make two arrays next smaller and prev smaller and both contains indices ,so just traverse over them and return max of next[i]-prev[i]-1.
class Solution {
private:
    vector<int> nextSmallestElement(vector<int> arr,int n){
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            int curr = arr[i];
            while(st.top() != -1 && arr[st.top()] >= curr){
                st.pop();
            }
            ans[i]=st.top();
            //since we are talking for indices.
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmallestElement(vector<int> arr,int n){
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for(int i=0;i<n;i++){
            int curr = arr[i];
            while(st.top() != -1 && arr[st.top()] >= curr){
                st.pop();
            }
            ans[i]=st.top();
            //since we are talking for indices.
            st.push(i);
    }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> next;
        next = nextSmallestElement(heights,n);
        vector<int> prev;
        prev = prevSmallestElement(heights,n);
        
        int maxArea = INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            
            if(next[i] == -1)
                next[i] = n;
            int b = next[i] - prev[i] -1;
            int area = l*b;
            
            maxArea=max(maxArea,area);
        }
        return maxArea;
        
    }
};