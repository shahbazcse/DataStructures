// Link: https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

// Approach: [TC: O(N)]

class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        Node* temp = head;
        
        int cnt=0;
        
        while(temp){
            cnt++;
            temp=temp->next;
        }
        
        temp=head;
        
        cnt=(cnt/2);
        while(cnt--){
            temp=temp->next;
        }
        
        int ans=temp->data;
        
        return ans;
    }
};