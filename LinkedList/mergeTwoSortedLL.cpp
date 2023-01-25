// Link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

// Approach: [TC: O(N+M)]

Node* sortedMerge(Node* head1, Node* head2)  
{  
    if(!head1) return head2;
    if(!head2) return head1;
    
    Node* temp1 = head1;
    Node* temp2 = head2;
    
    Node* dummy = new Node(-1);
    Node* tail = dummy;
    
    while(temp1 && temp2){
        if(temp1->data < temp2->data){
            tail->next=temp1;
            tail=tail->next;
            temp1=temp1->next;
        }else{
            tail->next=temp2;
            tail=tail->next;
            temp2=temp2->next;
        }
    }
    tail->next=NULL;
    
    if(temp1){
        tail->next=temp1;
    }
    
    if(temp2){
        tail->next=temp2;
    }
    
    dummy=dummy->next;
    return dummy;
}