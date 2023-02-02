// Link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

// Approach 1: Brute Force [TC: O(NLogN)]

Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node* temp1=head1;
    Node* temp2=head2;
    
    vector<int> ds;
    
    while(temp1){
        ds.push_back(temp1->data);
        temp1=temp1->next;
    }
    
    while(temp2){
        ds.push_back(temp2->data);
        temp2=temp2->next;
    }
    
    sort(ds.begin(),ds.end());
    
    Node* head = new Node(-1);
    Node* tail = head;
    
    for(auto i:ds){
        Node* newNode = new Node(i);
        tail->next=newNode;
        tail=tail->next;
    }
    tail->next=NULL;
    
    return head->next;
}

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