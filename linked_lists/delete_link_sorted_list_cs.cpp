Node * uniqueSortedList(Node * head) {
    // Write your code here.
    if(head == NULL)
        return NULL;
    
    //non empty list
    Node* curr = head;
    while(curr != NULL){
        if(curr ->next != NULL && curr -> data == curr -> next -> data){
            Node* next_next = curr -> next -> next;
            Node* nodetodelete = curr -> next;
            delete(nodetodelete);
            curr -> next = next_next;
        }
        else{
            curr = curr -> next;
        }
    }
    return head;
}