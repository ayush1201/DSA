//floyd algorithm based on slow and fast pointer.
Node *findMiddle(Node *head) {
    // Write your code here
//     int len = getlen(head);
//     int ans=len/2;
//     Node* temp=head;
//     while(ans>0){
//         temp = temp -> next;
//         ans--;
//     }
//     return temp;
    if(head == NULL || head -> next == NULL)
        return head;
    Node* slow = head;
    Node* fast = head -> next;
    while(fast != NULL){
        //if even check fast not becomes NULL.
        fast = fast->next;
        if(fast!=NULL){
            fast = fast -> next;
        }
        slow = slow->next;
    }
    return slow;
   
}