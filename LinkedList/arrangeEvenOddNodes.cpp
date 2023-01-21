// Link: https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

// Approach: [TC: O(N)]

class Solution{
public:
    Node* divide(int N, Node *head){
        Node* curr = head;
        Node* even = new Node(-1);
        Node* evenHead = even;
        Node* odd = new Node(-1);
        Node* oddHead = odd;
        
        while(curr){
            // Even
            if((curr->data)%2==0){
                Node* temp = new Node(curr->data);
                even->next=temp;
                even=even->next;
            }
            // Odd
            else{
                Node* temp = new Node(curr->data);
                odd->next=temp;
                odd=odd->next;
            }
            curr=curr->next;
        }
        
        even->next=oddHead->next;
        oddHead->next=NULL;
        delete oddHead;
        
        even=evenHead->next;
        evenHead->next=NULL;
        delete evenHead;
        
        return even;
    }
};