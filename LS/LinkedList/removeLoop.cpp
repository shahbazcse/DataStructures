// Link: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

// Approach: [TC: O(N)]

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    Node* isLoop(Node* head){
        Node* slow = head;
        Node* fast = head;
        
        while(slow && fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return fast;
            }
        }
        return NULL;
    }
    void removeLoop(Node* head)
    {
        if(!isLoop(head)) return;
        
        Node* fast = isLoop(head);
        Node* slow = head;
        
        // If LL is Circular
        if(fast==head){
            while(fast->next!=head){
                fast=fast->next;
            }
            fast->next=NULL;
            return;
        }
        
        while(fast->next!=slow->next){
            fast=fast->next;
            slow=slow->next;
        }
        fast->next=NULL;
        return;
    }
};