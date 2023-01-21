// Link: https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

// Approach: [TC: O(N)]

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node* slow = head;
        Node* fast = head->next;
        
        // Find mid
        while(fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        // Reverse from mid
        Node* prev = NULL;
        Node* mid = slow->next;
        Node* forward = NULL;

        while(mid){
            forward = mid->next;
            mid->next=prev;
            prev=mid;
            mid=forward;
        }
        
        // Compare nodes
        Node* curr = head;
        mid=prev;
        while(mid){
            if(curr->data!=mid->data) return 0;
            mid=mid->next;
            curr=curr->next;
        }
        return 1;
    }
};