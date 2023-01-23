// Link: https://practice.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1

// Approach: [TC: O(N)]

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        Node* head = new Node(-1);
        Node* tail = head;
        
        for(int i=0; i<arr.size(); i++){
            Node* temp = new Node(arr[i]);
            tail->next=temp;
            temp->prev=tail;
            tail=tail->next;
        }
        tail->next=NULL;
        
        head=head->next;
        head->prev=NULL;
        
        return head;
    }
};