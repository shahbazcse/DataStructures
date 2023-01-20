// Link: https://practice.geeksforgeeks.org/problems/count-nodes-of-linked-list/0

// Approach: [TC: O(N)]

class Solution
{
    public:
    //Function to count nodes of a linked list.
    int getCount(struct Node* head){
        Node* temp = head;
        int cnt=0;
        
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
};