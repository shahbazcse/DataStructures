// Link: https://practice.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1

// Approach: [TC: O(N)]

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        Node* temp = head;
        while(temp){
            if(temp->data==key) return true;
            temp=temp->next;
        }
        return false;
    }
};