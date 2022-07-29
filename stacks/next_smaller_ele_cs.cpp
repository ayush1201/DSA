#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> st;
    st.push(-1);
    vector<int> res;
    int ans = -1;
    
    for(int i=n-1;i>=0;i--){
        int curr = arr[i];
        while(st.top() >= curr){
            st.pop();
        }
        
        //ans hai stack ka top.
        arr[i] = st.top();
        st.push(curr);
    }
    return arr;
}