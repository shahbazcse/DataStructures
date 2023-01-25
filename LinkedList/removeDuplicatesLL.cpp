// Link: https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

// Approach: [TC: O(N)]

class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        map<int,bool> found;
        
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr){
            if(found[curr->data]){
                prev->next = curr->next;
                delete curr;
            }
            else{
                found[curr->data]=true;
                prev = curr;
            }
            curr=prev->next;
        }
        return head;
    }
};