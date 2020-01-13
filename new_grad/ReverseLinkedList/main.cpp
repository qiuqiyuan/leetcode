//The idea is to append the first element to the end
//of the list. 
//This is very slow, O(n^2).
//
//What can I learn from this solution?
//Should think about an elegant iterative solution.

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


//This recursive solution is O(2n) 
//This is very neat
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *rest = reverseList(head->next);
        
        head->next->next = head;
        head->next = nullptr;
        
        return rest;
    }
};


//iterative version
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *h=nullptr, *p=nullptr;
        //Think about this as mostly moving head pointer along, 
        //but in between moving, change pointer direction and update new list head h.
        while(head){
            p = head->next;

            head->next = h;
            h = head;
        
            head = p;
        }
        return h;
    }
};
