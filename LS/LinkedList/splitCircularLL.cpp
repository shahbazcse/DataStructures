// Link: https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1

// Approach: [TC: O(N) / SC: O(1)]

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* prev = head;
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast!=head && fast->next!=head){
        slow=slow->next;
        prev=fast->next;
        fast=fast->next->next;
    }
    
    // Creating first half
    *head1_ref = head;
    *head2_ref = slow->next;
    slow->next=head;
    
    // Creating second half
    if(fast==head) prev->next=*head2_ref;
    else fast->next=*head2_ref;
}