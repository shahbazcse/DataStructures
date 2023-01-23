// Link: https://practice.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1

// Approach: [TC: O(N)]

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        struct Node* currNode = *head_ref;
        struct Node* forward = NULL;
        
        while(currNode){
            if(currNode->data==x){
                forward=currNode->next;
                
                if(*head_ref==NULL || currNode==NULL) return;
                if(*head_ref==currNode) *head_ref=currNode->next;
                if(currNode->next) currNode->next->prev = currNode->prev;
                if(currNode->prev) currNode->prev->next = currNode->next;
                
                delete currNode;
                
                currNode=forward;
            }
            else{
                currNode=currNode->next;
            }
        }
    }
};