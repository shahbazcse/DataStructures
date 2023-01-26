// Problem: Remove Duplicates from Sorted LL

    // Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

    // Approach 1: [TC: O(N)]

    class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if(head==NULL) return NULL;
            
            ListNode* currentNode = head;
            ListNode* temp = NULL;
            
            while(currentNode && currentNode->next!=NULL){
                if(currentNode->val==currentNode->next->val){
                    temp = currentNode->next;
                    currentNode->next = currentNode->next->next;
                    temp->next = NULL;
                    delete temp;
                }
                else currentNode=currentNode->next;
            }
            return head;
        }
    };

    // Approach 2: Use Map for visited/non-visited nodes

// Problem: Remove Duplicates from Unsorted LL

    // Link: https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331

    // Approach 1: [TC: O(N^2)]

    Node *removeDuplicates(Node *head)
    {
        Node* currentNode = head;
        Node* temp = NULL;
        Node* prev = NULL;
        
        while(currentNode && currentNode->next!=NULL){
            prev=temp;
            temp=currentNode->next;
            while(temp){
                if(currentNode->data==temp->data){
                    prev->next = temp->next;
                    delete temp;
                }
                else temp=temp->next;
            }
            currentNode=currentNode->next;
        }
        return head;
    }

    // Approach 2: [TC: O(N)]

    Node *removeDuplicates(Node *head)
    {
        Node* currentNode = head;
        Node* prevNode = NULL;
        unordered_map<int,bool> visited;
        
        while(currentNode){
            if(visited[currentNode->data]){
                prevNode->next = currentNode->next;
                delete currentNode;
            }
            else{
                visited[currentNode->data]=true;
                prevNode = currentNode;
                currentNode=currentNode->next;
            }
            currentNode=prevNode->next;
        }
        return head;
    }

    // Approach 3:
        // 1. Sort the LL
        // 2. Implement Remove Duplicates from Sorted LL Approach