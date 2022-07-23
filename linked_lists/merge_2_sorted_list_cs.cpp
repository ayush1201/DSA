Node<int>* solve(Node<int>* first, Node<int>* second){
    
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1 -> next;
    Node<int>* curr2 = second;
    Node<int>* next2 = NULL;
    
    //if only element is present in first.
    if(next1 == NULL){
        curr1 -> next = curr2 ;
        return first;
    }
    
    while(next1 != NULL && curr2 != NULL){
       if(curr2 ->data >= curr1 -> data && curr2 -> data < next1 -> data ){
           //add node in the given range of list 1.
           curr1 -> next = curr2;
           next2 = curr2 -> next;
           curr2 -> next = next1;
           
           curr1 = curr2;
           curr2 = next2;
       }
        else{
            curr1 = next1;
            next1 = next1 -> next;
            
            //check if next1 is null ,means first list is completed.
            if(next1 == NULL){
                curr1 -> next = curr2;
                return first;
            }
   
        }
    }
    return first;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first == NULL)
        return second;
    if(second == NULL) 
        return first;
    
    if(first -> data<=second -> data){
        return solve(first,second);
    }
    else{
        return solve(second,first);
    }
}