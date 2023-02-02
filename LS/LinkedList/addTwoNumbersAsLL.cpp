// Link: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

// Approach: [TC: O(N+M)]

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(Node* head){
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
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* head1 = reverse(first);
        Node* head2 = reverse (second);
        
        Node* head = new Node(-1);
        Node* tail = head;
        int carry=0;
        
        while(head1 || head2){
            if(head1){
                carry+=head1->data;
                head1=head1->next;
            }
            if(head2){
                carry+=head2->data;
                head2=head2->next;
            }
            if(carry>=10){
                tail->next=new Node(carry%10);
                tail=tail->next;
                carry=1;
            }else{
                tail->next=new Node(carry);
                tail=tail->next;
                carry=0;
            }
        }
        if(carry>0){
            tail->next=new Node(carry);
        }
        
        return reverse(head->next);
    }
};