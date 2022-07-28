//we will make a stack and push every bracket if it is open or else if it is closing we will check with last top open bracket and if matches then pop out last inserted open bracket . And if it doesn't matches with top bracket then return false. If stack is empty simply return false.
class Solution {
public:
    bool isValid(string s) {
        // Write your code here.
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        
        //if it is opening bracket pussh in stack.
        //if it is closing pop out of stack.
        
        if(ch == '{' || ch == '(' || ch == '['){
            st.push(ch);
        }
        else{
            if(!st.empty()){
                //checking stack top with ch.
                char top = st.top();
                if((ch == ')' && top == '(') || 
                   (ch == ']' && top == '[') ||
                   (ch == '}' && top == '{')){
                    st.pop();
                }
                else{
                    return false;
                }
                
            }
            //if stack is empty.
            else{
                return false;
            }
    }
    }
        if(st.empty())
            return true;
        else
            return false;
    }
};