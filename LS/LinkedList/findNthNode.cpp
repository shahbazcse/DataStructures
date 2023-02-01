// Link: https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

// Approach: [TC: O(N)]

int getNthFromLast(Node *head, int n)
{
       Node* temp = head;
       int cnt=0;
       
       while(temp){
           cnt++;
           temp=temp->next;
       }
       
       int nodeToFind=cnt-n;
       if(nodeToFind<0) return -1; 
       
       temp = head;
       while(nodeToFind--){
           temp=temp->next;
       }
       
       return temp->data;
}