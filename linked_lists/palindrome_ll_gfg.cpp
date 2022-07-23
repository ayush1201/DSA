//O(n) time and o(n) space since we are creating an array.
#include<vector>
class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        vector<int> arr;
        Node* temp = head;
        while(temp != NULL){
            arr.push_back(temp->data);
            temp = temp -> next;
        }
        int start = 0;
        int end = arr.size()-1;
        while(start<=end){
            if(arr[start] != arr[end])
                return false;
            else{
                start++;
                end--;
            }
        }
        return true;
    }
};


//approach 2 , main logic we will find the mid of link list and then after mid rerverse the link list . Then keep one pointer at head and another at mid -> next ,compare if equal then palindrome.
class Solution{
  private:
    Node* getmid(Node* head){
        Node* slow = head;
        Node* fast = head -> next;
        while(fast != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast -> next;
                slow = slow -> next;
            }
            
        }
        return slow;
    }
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head == NULL || head -> next == NULL)
         return true;
         
        Node* middle = getmid(head); 
        Node* temp = middle -> next;
        middle -> next = reverse(temp);
        //now check last condition and loop from middle node.
        
        Node* head1 = head;
        Node* head2 = middle -> next;
        while(head2 != NULL){
            if(head1 -> data != head2 -> data)
             return false;
             
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        
        return true;
    }
};