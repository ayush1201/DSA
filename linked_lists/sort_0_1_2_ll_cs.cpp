//concept is count number of 0,1,2 and then traverse each list and put that number of 0,1,2 and complexity will be O(n).
Node* sortList(Node *head)
{
    // Write your code here.
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    
    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == 0)
            zeroCount++;
        else if(temp -> data == 1)
            oneCount++;
        else if(temp -> data == 2)
            twoCount++;
        
        temp = temp ->next;
    }
    
    temp = head;
    while(temp!=NULL){
        if(zeroCount != 0){
            temp ->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){
            temp -> data = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            temp -> data = 2;
            twoCount--;
        }
        temp = temp -> next;
    }
return head;
}

//2nd approach using merging concept.
//basic concept is making zero,one and two linked list seperately and then merge them all one by one.
Node* insertAttail(Node* &tail,Node* curr){
    tail -> next = curr;
    tail = curr;
}
Node* sortList(Node *head)
{
    // Write your code here.
    //creating three lists.
    //creating lists with dummy values to prevent multiple if statements.
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node * twoTail = twoHead;
    
    Node* curr = head;
    while(curr != NULL){
        if(curr -> data == 0)
            insertAttail(zeroTail,curr);
        
        else if(curr -> data == 1)
            insertAttail(oneTail,curr);
        
        else if(curr -> data == 2)
            insertAttail(twoTail,curr);
        curr = curr -> next;
    }
    //now merging the three linkeed lists.
    if(oneHead -> next != NULL ){ //one list is not empty.
        zeroTail -> next = oneHead -> next;
    }
    else{
        zeroTail -> next = twoHead -> next;
    }
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    head = zeroHead -> next;  
    //deleting dummy nodes.
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
return head;
}