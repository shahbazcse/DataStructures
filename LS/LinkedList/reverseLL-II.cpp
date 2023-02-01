// Link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

// Approach: [TC: O(N)]

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node* curr=head;
        Node* prev=NULL;
        Node* forward = NULL;
        
        while(curr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        return prev;
    }
};