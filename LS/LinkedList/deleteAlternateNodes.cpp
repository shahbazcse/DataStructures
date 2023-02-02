// Link: https://practice.geeksforgeeks.org/problems/delete-alternate-nodes/1

// Approach: [TC: O(N)]

void deleteAlt(struct Node *head){
    int cnt=1;
    Node* prev = head;
    while(prev){
        if(cnt%2!=0){
            if(prev->next==NULL) break;
            Node* curr=prev->next;
            Node* forward=curr->next;
            prev->next=forward;
            
            curr->next=NULL;
            delete curr;
            
            prev=forward;
        }
    }
}