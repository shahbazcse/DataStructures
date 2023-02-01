// Link: https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

// Approach 1: [TC: O(N)]

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

// Approach 2: 2 Pointer [TC: O(N)]

class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow->data;
    }
};

// Aproach 3: 2 Pointer + Recursion [TC: O(N)]

class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int findMiddle(Node* head, int s, int e){
        if(s>=e) return head->data; // base case
        
        s++; // moving s one step ahead
        e--; // moving e one step back
        
        return findMiddle(head->next,s,e); // recursive call
    }
    
    int getMiddle(Node *head)
    {
        Node* temp = head;
        
        int s=1;
        
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        
        int e=cnt;
        
        return findMiddle(head,s,e);
    }
};