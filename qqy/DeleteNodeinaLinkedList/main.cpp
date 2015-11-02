//I never thought about first duplicating the next 
//element and then keep the current and remove the next one
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
    void deleteNode(ListNode* node) {
        if(!node->next) return;
        ListNode* next = node->next;
        *node = *next;
        delete next;
    }
};
