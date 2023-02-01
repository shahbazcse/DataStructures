// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/

// Approach: Recursion [TC: O(N)]

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        ListNode* temp = head;
        int cnt=0;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        
        int i=0;
        if(cnt>=k){
            while(curr && i<k){
                forward=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forward;
                i++;
            }
            if(forward) head->next = reverseKGroup(forward,k);
        }else return head;
        return prev;
    }
};

// Link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

// Approach: Recursion [TC: O(N)]

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        struct node* temp = head;
        
        int cnt=0;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        
        if(cnt>=k){
            struct node* prev = NULL;
            struct node* curr = head;
            struct node* forward = NULL;
            
            int i=0;
            while(curr && i<k){
                forward=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forward;
                i++;
            }
            
            head->next = reverse(forward,k);
            head=prev;
            return prev;
            
        }else{
            struct node* prev = NULL;
            struct node* curr = head;
            struct node* forward = NULL;
            
            while(curr){
                forward=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forward;
            }
            return prev;
        }
    }
};