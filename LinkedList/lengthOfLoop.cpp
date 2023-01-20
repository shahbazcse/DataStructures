// Link: https://practice.geeksforgeeks.org/problems/find-length-of-loop/1

// Approach: [TC: O(N)]

int countNodesinLoop(struct Node *head)
{
    Node* slow = head;
    Node* fast = head;
    
    while(slow && fast && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            int cnt=1;
            slow=slow->next;
            while(slow!=fast){
                slow=slow->next;
                cnt++;
            }
            return cnt;
        }
    }
    return 0;
}