// Link: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

// Approach: [TC: O(N+M)]

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

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* l1 = reverse(first);
        Node* l2 = reverse(second);
        
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        int carry=0;
        
        while(l1 || l2 || carry){
            int sum=0;
            
            if(l1){
                sum+=l1->data;
                l1=l1->next;
            }
            
            if(l2){
                sum+=l2->data;
                l2=l2->next;
            }
            
            sum+=carry;
            
            temp->next= new Node(sum%10);
            temp=temp->next;
            carry=sum/10;
        }
        if(carry){
            temp->next = new Node(carry);
            temp=temp->next;
            temp->next=NULL;
        }
        
        dummy=dummy->next;
        
        return reverse(dummy);
    }
};