// Link: https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1

// Approach: [TC: O(N)]

class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        if(head==NULL || head->next==NULL) return head;
        
        struct Node* curr=head;
        struct Node* forward= curr->next;
        curr->next=forward->next;
        forward->next=curr;
        
        if(curr->next){
            curr->next= pairWiseSwap(curr->next);
        }
        
        return forward;
    }
};