// Link: https://practice.geeksforgeeks.org/problems/delete-middle-of-linked-list/1

// Approach: [TC: O(N)]

Node* deleteMid(Node* head)
{
    Node* prev=NULL;
    Node* slow=head;
    Node* fast=head;
    
    while(fast && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    
    prev->next = slow->next;
    slow->next=NULL;
    delete slow;
    
    return head;
}