Node* kReverse(Node* head, int k) {
    // Write your code here.
    //base case
    if(head == NULL){
        return NULL;
    }
    int count=0;
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr != NULL && count<k){
        next = curr ->next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    //recursive call
    if(next != NULL){
        head -> next = kReverse(next,k);
    }
    //case 3 return head of ther reverse list.
    //since list is reversed so prev will be the head.
    return prev;
    