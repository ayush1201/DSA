//for detecting loop we use floyd algo which is slow and fast pointer algo , and for getting head node of the loop we run one slow from head and intersection from fast and increment by one both pointers till they meet. Now to delete run loop till temp->next!=intersecton node and then simply point temp to NULL.
Node* floydCycle(Node* head){
    if(head == NULL)
        return NULL;
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
        
        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}

Node* getStartNode(Node *head){
    if(head == NULL)
        return NULL;
    Node* intersection = floydCycle(head);
    if(intersection == NULL)
        return NULL;
    
    Node* slow = head;
    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }
    return slow;
}

Node *removeLoop(Node *head)
{
    // Write your code here.
    //for getting the meeting point which ensures cyclic nature of list.
    if(head == NULL)
        return NULL;
    Node* StartNode = getStartNode(head);
    if(StartNode == NULL)
        return head;
    Node* temp = StartNode;
    //traversing till temp ka next node startnode hota hai .
    while(temp->next != StartNode){
        temp = temp -> next;
    }
    //breaking the cycle loop by pointing last node to null.
    temp -> next = NULL;
    return head;
    
    
}