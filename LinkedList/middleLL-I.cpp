// Approach 1:
class Solution {
public:
    ListNode* middleLL(ListNode* &head, int &start, int &end){
        if(start>=end){
            return head;
        }
        head=head->next;
        start++;
        end--;
        return middleLL(head,start,end);
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;

        int start=1;
        int end=0;
        while(temp){
            temp=temp->next;
            end++;
        }

        return middleLL(head,start,end);
    }
};

// Approach 2:
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* fast = head;
        ListNode* slow = head;
        // checking 'fast' for even nodes and 'fast->next' for odd nodes
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }
};