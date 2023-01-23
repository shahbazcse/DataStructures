// Link: https://practice.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

// Approach: [TC: O(N)]

class Solution
{
    public:
    Node* deleteNode(Node *head_ref, int x)
    {
      Node* curr = head_ref;
      
      // Insert at head
      if(x==1){
          head_ref=head_ref->next;
          head_ref->prev=NULL;
          curr->next=NULL;
          delete curr;
          return head_ref;
      }
      
      int i=1;
      while(curr){
          if(i==x-1){
            Node* temp = curr->next;
            curr->next=temp->next;
            
            if(temp->next!=NULL) temp->next->prev=curr;
            
            temp->next=NULL;
            temp->prev=NULL;
            
            delete temp;
          
            break;
          }
          i++;
          curr=curr->next;
      }
      return head_ref;
    }
};