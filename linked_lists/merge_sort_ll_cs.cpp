node* findMid(node* head){
    node* slow = head;
    node* fast = head -> next;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
} 
node* merge(node* left,node* right){
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
    
    //creating dummy node.
    node* ans = new node(-1);
    node* temp = ans;
    
    //merging two lists.
    while(left != NULL && right != NULL){
        if(left -> data < right -> data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    //if left becomes NULL.
    while(right!=NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    //if right becomes null.
    while(left != NULL){
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    //since answer is dummy node.
    ans = ans -> next;
    return ans;
}
node* mergeSort(node *head) {
    // Write your code here.
    //base case
    if(head == NULL || head -> next == NULL)
        return head;
    
    //breaking into left and right.
    node* mid = findMid(head);
    node* left = head;
    node* right = mid -> next;
    mid -> next = NULL;
    
    //recursive call.
    left = mergeSort(left);
    right = mergeSort(right);
    
    //merge both left and right.
    node* result = merge(left,right);
    return result;
}