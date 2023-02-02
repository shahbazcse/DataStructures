// Link: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

// Approach 1: [TC: O(N+M) / SC: O(1)]

int intersectPoint(Node* head1, Node* head2)
{
    Node* temp1=head1;
    Node* temp2=head2;
    
    while(1){
        if(temp1==temp2) return temp1->data;
        
        if(!temp1 && !temp2) return -1;
        
        if(!temp1) temp1=head2;
        if(!temp2) temp2=head1;
        
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return -1;
}

// Approach 2: Hashing [TC: O(N) / SC: O(N)]

int intersectPoint(Node* head1, Node* head2)
{
    Node* temp1=head1;
    Node* temp2=head2;
    
    unordered_set<Node*> S;
    
    while(temp1){
        S.insert(temp1);
        temp1=temp1->next;
    }
    
    while(temp2){
        if(S.find(temp2)!=S.end()) return temp2->data;
        temp2=temp2->next;
    }
    
    return -1;
}