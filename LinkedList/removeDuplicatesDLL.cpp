// Link: https://practice.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

// Approach: [TC: O(N)]

class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        struct Node* prevNode = head;
        struct Node* currNode = head->next;
        
        while(currNode){
            if(currNode->data==prevNode->data){
                if(prevNode==head) head=currNode;
                currNode->prev=prevNode->prev;
                if(prevNode->prev) prevNode->prev->next=currNode;
                
                delete prevNode;
            }
            prevNode=currNode;
            currNode=currNode->next;
        }
        return head;
    }
};