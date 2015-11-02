//The idea is to append the first element to the end
//of the list. 
//This is very slow, O(n^2).
//
//What can I learn from this solution?
//Should think about an elegant iterative solution.
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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *rest = reverseList(head->next);
        ListNode *node = rest;
        while(node->next) node = node->next;
        node->next = head;
        head->next = nullptr;
        return rest;
    }
};
