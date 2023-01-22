// Link: https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

// Approach: [TC: O(N)]

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        Node* temp = head;
        Node* prev = head;
        
        while(temp->next!=NULL){
            if(temp->data!=9){
                prev=temp;
            }
            temp=temp->next;
        }
        
        if(temp->data==9){
            prev->data++;
            prev=prev->next;
            while(prev){
                prev->data=0;
                prev=prev->next;
            }
        }else{
            temp->data++;
        }
        
        return head;
    }
};