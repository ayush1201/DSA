//appraoch 1 using maps. The concept is first create clone list and copy all the values of original list in clone list. Then store the original node in clone node and then access the random pointer through map.
//o(n) time and o(n) space.
class Solution {
private:
    private:
    void insertAtTail(Node* &head,Node* &tail,int data){
        Node* newNode = new Node(data);
        if(head == NULL){
         head = newNode;
         tail = newNode;
         return;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
         
    }
public:
    Node* copyRandomList(Node* head) {
        //Write your code here
        //step 1 creating clone link list.
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead,cloneTail,temp -> val);
            temp = temp -> next;
        }
        
        //create a map
        unordered_map<Node*,Node*> oldToNewNode;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL){
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        //map is created with all values cloned in oldToNewNode map.
        
        //now just traversing again and check for random pointer in the stored values in map.
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL){
            cloneNode -> random = oldToNewNode[originalNode -> random];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        return cloneHead;
    }
};

//approach 2 , o(n) time and o(1) space .
//concept is without using maps just modify the pointers .

private:
    void insertAtTail(Node* &head,Node* &tail,int d){
         Node* newNode = new Node(d);
         if(head == NULL){
             head = newNode;
             tail = newNode;
             return;
         }
         
         tail -> next = newNode;
         tail = newNode;
     }
public:
    Node *copyList(Node *head)
    {
        //Write your code here
        //step1 : create a clone list.
        Node* temp = head;
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        while(temp != NULL){
            insertAtTail(cloneHead,cloneTail,temp -> data);
            temp = temp -> next;
        }
        //step2 : insert clone list in between original list.
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
            //for original node.
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            //for clone node.
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = next;
        }
        //step3 : copying random pointers .
        
        temp = head;
        while(temp != NULL){
            if(temp -> next != NULL)
             temp -> next -> arb = temp->arb ? temp -> arb -> next : temp -> arb;
            
            //do baar badana padega kyunki linear nhi hai relation and temp -> next point kar raha hoga cloneNode ko.
            temp = temp -> next;
            temp = temp -> next;
        }
        //step4 : revert changes.
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
            originalNode -> next = cloneNode -> next;
            originalNode = originalNode -> next;
            if(originalNode != NULL){
                cloneNode ->next = originalNode -> next;
                
            }
            cloneNode = cloneNode -> next;
        }
        
        //step5 : return ans. 
        return cloneHead;
    }     