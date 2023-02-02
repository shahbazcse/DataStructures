// Link: https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

// Approach 1: [TC: O(N+M)]

Node* findIntersection(Node* head1, Node* head2)
{
    Node* temp1=head1;
    Node* temp2=head2;
    
    Node* head3=new Node(-1);
    Node* tail=head3;
    
    while(temp1 && temp2){
        if(temp1->data==temp2->data){
            Node* newNode= new Node(temp1->data);
            tail->next=newNode;
            tail=tail->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->data < temp2->data) temp1=temp1->next;
        else temp2=temp2->next;
    }
    tail->next=NULL;
    return head3->next;
}

// Approach 2: Hashing [TC: O(N+M) / SC: O(N+M)]

Node* findIntersection(Node* head1, Node* head2)
{
    Node* temp1=head1;
    Node* temp2=head2;
    
    map<int,int> m;
    
    while(temp1){
        m[temp1->data]++;
        temp1=temp1->next;
    }
    
    while(temp2){
        m[temp2->data]++;
        temp2=temp2->next;
    }
    
    Node* head=new Node(-1);
    Node* tail=head;
    
    for(auto it:m){
        if(it.second>1){
            for(int i=1; i<=it.second/2; i++){
                Node* newNode = new Node(it.first);
                tail->next=newNode;
                tail=tail->next;
            }
        }
    }
    tail->next=NULL;
    return head->next;
}