// Link: https://practice.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1

// Approach: TC[O(N)]

Node* deleteNode(Node *head,int x)
{
    Node* temp = head;
    Node* prev = NULL;
    int cnt=0;
    
    while(temp){
        cnt++;
        if(cnt==x) break;
        prev=temp;
        temp=temp->next;
    }
    
    // If the first node of the LL has to be deleted
    if(temp==head){
        head=temp->next;
        temp->next=NULL;
        delete temp;
        
        return head;
    }
    
    prev->next=temp->next;
    temp->next=NULL;
    delete temp;
    
    return head;
}