class compare{ 
    public:
     bool  operator()(ListNode* a,ListNode* b){
      return a -> val > b -> val;
     }    
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*,vector<ListNode*>,compare> minHeap;
    //step1 insertin head of linked linsts in minheap.
        
    int k = lists.size();
    for(int i=0;i<k;i++){
        if(lists[i] != NULL){
           minHeap.push(lists[i]);            
        }
    }
    
        //step2 checking if head is null then make head,tail pointng to temp and inserting tail -> next to minheap else just point tail to temp and minheap is pushed with tail -> next is exists.
    ListNode* head = NULL;
    ListNode* tail = NULL;
    while(!minHeap.empty()){
        ListNode* temp = minHeap.top();
        minHeap.pop();
        
        //check if list is empty or it is not empty.
        if(head == NULL){
            head = temp;
            tail = temp;
            if(tail -> next != NULL){
                minHeap.push(tail -> next);
            }
        }
        else{
            tail -> next = temp;
            tail = temp;
            if(tail -> next != NULL){
                minHeap.push(tail -> next);
            }
        }
    }
        return head;
    }
};