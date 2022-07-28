//concept is if there is no operator to consume within opening and closing brackets means it is redundant brackets.
#include<stack>
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            st.push(ch);
        else{
            //means ch is closing bracket or lower case character.
            if(ch == ')'){
                bool redundant = true;
            
            while(st.top() != '('){
                char top = st.top();
                if(top == '+' || top == '-' || top == '*' || top == '/'){
                    redundant = false;
                }
                st.pop();
                
            }
            if(redundant == true){
                return true;
            }
            st.pop();
        }
        }     
    }
    return false;
}