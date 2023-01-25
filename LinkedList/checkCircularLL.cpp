// Link: https://practice.geeksforgeeks.org/problems/circular-linked-list/1

// Approach: [TC: O(N)]

bool isCircular(Node *head)
{
   Node* temp = head->next;
   
   while(temp){
       if(temp==head) return 1;
       temp=temp->next;
   }
   return 0;
}