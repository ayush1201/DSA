int getlen(Node* head){
    int len=0;
    while(head!=NULL){
        head = head -> next;
        len++;
    }
    return len;
}
Node *findMiddle(Node *head) {
    // Write your code here
    int len = getlen(head);
    int ans=len/2;
    Node* temp=head;
    while(ans>0){
        temp = temp -> next;
        ans--;
    }
    return temp;
    
}