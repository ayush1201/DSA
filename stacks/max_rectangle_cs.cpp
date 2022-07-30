class Solution{
  private:
    
    vector<int> nextSmallestElement(int* arr,int n){
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
    
    vector<int> prevSmallestElement(int* arr,int n){
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
    
    int largestRectangleArea(int* heights,int n) {
        //int n=heights.size();
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
    
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        //compute area for first row.
        int area = largestRectangleArea(M[0],m);
        
        //now for further rows and check max area.
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                //row update by adding previous rows.
                if(M[i][j] == 1)
                 M[i][j] = M[i-1][j] + M[i][j];
                else
                 M[i][j] = 0;
            }
            //entire row is updated.
            //checking for max area in previous stored and next row max area.
            area = max(area,largestRectangleArea(M[i],m));
        }
        return area;
    }
};