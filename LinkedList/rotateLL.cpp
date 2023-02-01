// Link: https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

// Approach: [TC: O(N)]

class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node* tail=head;
        while(tail->next!=NULL) tail=tail->next;
        
        Node* curr=head;
        
        while(k>0){
            tail->next=head;
            head=head->next;
            curr->next=NULL;
            curr=head;
            tail=tail->next;
            k--;
        }
        return head;
    }
};

// Approach 2: 

class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node* tail = head;
        
        // move tail to last node
        while(tail->next!=NULL) tail=tail->next;
        
        // connect tail to head
        tail->next=head;
        
        // put curr on tail node
        Node* curr = tail;
        
        // move curr from tail to kth node
        while(k--){
            curr=curr->next;
        }
        
        // update head
        head=curr->next;

        // update last node
        curr->next=NULL;
        
        return head;
    }
};