// Approach 1: Floyd's Cycle Detection Algorithm
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

// Approach 2: using Map for visited/non-visited nodes

bool detectLoop(ListNode* head){
    if(head==NULL) return false;

    map<ListNode*, bool> visited;

    ListNode* temp = head;

    while(temp){
        // Loop present
        if(visited[temp]) return true;
        
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}