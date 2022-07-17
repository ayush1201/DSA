LinkedListNode<int> *reverse(LinkedListNode<int> *head){
    //base case
    if(head == NULL || head -> next ==NULL){
        return head;
    }
    LinkedListNode<int> *chotahead = reverse(head -> next);
    head -> next -> next = head;
    head -> next =NULL;
    return chotahead;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
//     if(head == NULL || head->next ==NULL){
//         return head;
//     }
//     LinkedListNode<int> *prev=NULL;
//     LinkedListNode<int> *curr=head;
//     LinkedListNode<int> *forward=NULL;
//     while(curr!=NULL){
//         forward=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=forward;
//     }
//     return prev;
    return reverse(head);
    
    
}