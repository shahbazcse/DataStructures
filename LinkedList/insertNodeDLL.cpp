// Link: https://practice.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1

// Approach: [TC: O(N)]

void addNode(Node *head, int pos, int data)
{
    Node* curr=head;
   int i=0;
   while(curr){
       if(i==pos){
           Node* temp = new Node(data);
           Node* forward = curr->next;
           curr->next=temp;
           temp->next=forward;
           temp->prev=curr;
           break;
       }
       i++;
       curr=curr->next;
   }
}