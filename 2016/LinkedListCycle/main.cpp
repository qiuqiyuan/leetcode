//The idea is to have two pointers, fast and slow. 
//If the fast can catch up with the slow one, then
//there is a cycle.
//
//The tricky part is in the while condition:
//      fast->next && fast->next->next
//Otherwise it is going to have RTE for the program 
//may dereference a null pointer. 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }
};
