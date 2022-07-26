//concept is using recursion it will handle the next all part ,and then we will merge the first and second(which is all next part pointer ).
Node* merge(Node* first,Node* second){
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;
    
    Node* res;
    if(first -> data < second -> data){
        res = first;
        res -> child = merge(first -> child,second);
    }
    else{
        res = second;
        res -> child = merge(first , second -> child);
    }
    res -> next = NULL;
    return res;
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    if(head == NULL || head -> next == NULL)
        return head;
    
    return merge(head,flattenLinkedList(head -> next));
}