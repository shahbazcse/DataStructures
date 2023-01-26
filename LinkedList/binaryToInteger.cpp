// Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

// Approach 1: [TC: O(N)]

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int ans = 0;
        while(temp){
            ans *= 2;
            ans += temp->val;
            temp=temp->next;
        }
        return ans;
    }
};

// Approach 2: Reverse LL [TC: O(N)]

class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev= NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        while(curr){
            forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    int getDecimalValue(ListNode* head) {
        ListNode* temp = reverse(head);
        int ans=0;
        int i=0;
        while(temp){
            if(temp->val!=0){
                ans+=pow(2,i);
            }
            i++;
            temp=temp->next;
        }
        return ans;
    }
};