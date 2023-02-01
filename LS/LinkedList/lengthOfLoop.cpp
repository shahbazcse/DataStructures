// Link: https://practice.geeksforgeeks.org/problems/find-length-of-loop/1

// Approach: [TC: O(N)]

int countNodesinLoop(struct Node *head)
{
    Node* slow = head;
    Node* fast = head;
    
    while(fast && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    
    if(slow!=fast) return 0;
    
    int cnt=1;
    
    while(slow->next!=fast){
        slow=slow->next;
        cnt++;
    }
    
    return cnt;
}