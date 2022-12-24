class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow && fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) return 1;
        }
        return 0;
    }
};