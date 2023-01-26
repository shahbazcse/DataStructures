// Link: https://leetcode.com/problems/delete-node-in-a-linked-list/

// Approach: [TC: O(1)]

class Solution {
public:
    // 'head' of the LL is not given, only the 'node' to be deleted is given
    void deleteNode(ListNode* node) {

        if(node->next==NULL) delete node;
        
        swap(node->val,node->next->val);

        ListNode* temp = node->next;
        node->next = temp->next;
        temp->next=NULL;
        delete temp;
    }
};