// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/

// Approach: Recursion [TC: O(N)]

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;

        ListNode* prevNode = NULL;
        ListNode* currentNode = head;
        ListNode* forward = NULL;
        ListNode* temp = head;

        int cnt = 0;
        while(temp){
            temp = temp->next;
            cnt++;
        }

        int i=0;
        if(cnt>=k){
            while(currentNode && i<k){
                forward = currentNode->next;
                currentNode->next = prevNode;
                prevNode = currentNode;
                currentNode = forward;
                i++;
            }
            if(forward) head->next = reverseKGroup(forward,k);
        }
        else return head;
        
        return prevNode;
    }
};