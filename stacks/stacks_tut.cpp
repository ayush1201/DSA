#include<iostream>
#include<stack>
using namespace std;

class Stack{
    public:
      int *arr;
      int top;
      int size;
    //constructor.
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }  

    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"stack overflow "<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack under flow "<<endl;
        }
    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            return -1;
        }
    }
    bool isempty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    Stack st(3);

    st.push(1);
    st.push(2);
    st.push(3);

    st.pop();
    cout<<st.peek()<<endl;
    // stack<int> s;
    // s.push(2);
    // s.push(4);
    // s.push(6);

    // s.pop();
    // cout<<"the top element is "<<s.top()<<endl;
    return 0;
}