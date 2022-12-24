// Problem: Convert Binary Number in a Linked List to Integer
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