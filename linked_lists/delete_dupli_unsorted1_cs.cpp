//O(n*n) is uoptimised one.
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

//optimized approach with maps.
//O(n) time complexity.
    map<int, bool> visited;
    Node* prev = head;
    Node* curr = prev -> next;
    
    visited[prev ->data] = true;
    while(curr != NULL){
        if(visited[curr -> data] == true){
            prev -> next = curr -> next;
            delete(curr);
        }
        else{
            visited[curr -> data] = true;
            prev = prev -> next;
        }
        curr = curr -> next;
    }
    return head;