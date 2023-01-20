// Link: https://practice.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0

// Approach: [TC: O(1)] for insertAtBegining and [TC: O(N)] for insertAtEnd

class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       Node* temp = new Node(x);
       
       temp->next=head;
       head=temp;
       return head;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       Node* temp= new Node(x);
       if(head==NULL){
            return temp;
       }
       
       Node* curr = head;
       
       while(curr->next!=NULL){
           curr=curr->next;
       }
       curr->next=temp;
       temp->next=NULL;
       return head;
    }
};