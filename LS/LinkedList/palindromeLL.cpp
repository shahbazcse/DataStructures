// Link: https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

// Approach: Reverse from Middle Node [TC: O(N)]

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node* slow=head;
        Node* fast=head;
        
        // Find mid
        while(fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        // Reverse from mid
        Node* prev=NULL;
        Node* mid = slow;
        Node* forward=NULL;
        
        while(mid){
            forward=mid->next;
            mid->next=prev;
            prev=mid;
            mid=forward;
        }
        
        // Compare nodes
        Node* curr = head;
        while(prev){
            if(curr->data!=prev->data) return false;
            curr=curr->next;
            prev=prev->next;
        }
        return true;
    }
};

// Approach 2: Reverse LL [TC: O(N)]

class Solution{
  public:
    Node* reverse(Node* head){
        Node* prev=NULL;
        Node* curr=head;
        Node* forward=NULL;
        
        while(curr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    
    bool isPalindrome(Node *head)
    {
        Node* temp = head;
        Node* head2 = new Node(-1);
        Node* tail = head2;
        
        while(temp){
            Node* newNode = new Node(temp->data);
            tail->next=newNode;
            tail=tail->next;
            temp=temp->next;
        }
        tail->next=NULL;
        
        temp = head;
        Node* temp2 = reverse(head2->next);
        
        while(temp && temp2){
            if(temp->data!=temp2->data) return false;
            temp=temp->next;
            temp2=temp2->next;
        }
        return true;
    }
};