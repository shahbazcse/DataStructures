// Approach 1: Using Merge Sort

class Solution {
public:
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeLL(ListNode* left, ListNode* right){
        if(left==NULL) return right;
        if(right==NULL) return left;

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while(left && right){
            if(left->val<right->val){
                temp->next = left;
                temp = left;
                left = left->next;
            }else{
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        while(left){
            temp->next = left;
            temp = left;
            left = left->next;
        }

        while(right){
            temp->next = right;
            temp = right;
            right = right->next;
        }

        ans = ans->next;
        return ans;
    }
    ListNode* sortList(ListNode *head)
    {
        //Base case
        if(head==NULL || head->next==NULL)
            return head;

        //Find mid
        ListNode* mid = findMid(head);

        //Break into 2 halves
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        //Sort left/right halves recursively
        left = sortList(left);
        right = sortList(right);

        //Merge left/right sorted halves
        ListNode* result = mergeLL(left,right);

        //Return merged list
        return result;
    }
};