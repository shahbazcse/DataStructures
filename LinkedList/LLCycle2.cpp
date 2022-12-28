class Solution {
    public:
        ListNode* detectCycle(ListNode *head) {
            ListNode* slow = head;
            ListNode* fast = head;

            while(slow && fast && fast->next!=NULL){
                slow=slow->next; // At 1x speed
                fast=fast->next->next; // At 2x speed
                // Detect Loop
                if(fast==slow){
                    // Find starting node of Loop
                    ListNode* slow = head;
                    while(slow!=fast){
                        slow=slow->next; // At 1x speed
                        fast=fast->next; // At 1x speed
                    }
                    return slow;
                };
            }
            return NULL;
        }
};