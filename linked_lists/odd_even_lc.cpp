//using 2 pointers odd and even , we will traverse through list and try to point odd node to next -> next and even will point to next -> next.
//o(n) is time complexity.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        //more than 2 nodes present.
        ListNode* oddHead = head;
        ListNode* evenHead = head -> next;
        ListNode* odd = oddHead;
        ListNode* even = evenHead;
        
        while(odd -> next && even -> next){
            odd -> next = odd -> next -> next;
            odd = odd -> next;
            even -> next = even -> next -> next;
            even = even -> next;
        }
        
        odd -> next = evenHead;
        return oddHead;
    }
};