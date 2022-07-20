Node *removeDuplicates(Node *head)
{
    // Write your code here
    if(head == NULL)
        return NULL;
    Node* prev = head;
    Node* curr = NULL;
    
    while(prev != NULL && prev -> next != NULL){
        curr = prev;
        while(curr -> next != NULL ){
           
            if(curr ->next -> data == prev -> data){
                Node* duplicate = curr -> next;
                curr -> next = curr ->next ->next;
                delete(duplicate);
            }
            else{
                curr = curr -> next;
            }
        }
        prev = prev -> next;
    }
    return head;
}