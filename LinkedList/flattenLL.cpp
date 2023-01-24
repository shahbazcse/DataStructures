// Link: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

// Approach: [TC: O(N*N*M)]

Node* merge(Node* head1, Node* head2){
    Node* ans = new Node(-1);
    Node* temp = ans;
    
    while(head1 && head2){
        if(head1->data < head2->data){
            temp->bottom=head1;
            temp=temp->bottom;
            head1=head1->bottom;
        }else{
            temp->bottom=head2;
            head2=head2->bottom;
            temp=temp->bottom;
        }
    }
    
    if(head1){
        temp->bottom=head1;
        temp=temp->bottom;
    }
    
    if(head2){
        temp->bottom=head2;
        temp=temp->bottom;
    }
    
    ans=ans->bottom;
    return ans;
}

Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL) return root;
   
   Node* down = root;
   Node* right = flatten(root->next);
   
   down->next=NULL;
   
   return merge(down,right);
}