// Link: https://practice.geeksforgeeks.org/problems/introduction-to-linked-list/1

// Approach: [TC: O(N)]

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        Node* head = new Node(arr[0]);
        Node* curr=head;
        for(int i=1; i<arr.size(); i++){
            Node* temp=new Node(arr[i]);
            curr->next=temp;
            curr=curr->next;
        }
        return head;
    }
};