// Link: https://practice.geeksforgeeks.org/problems/intersection-of-two-linked-list/1

// Approach 1: [TC: O(N^2)] - TLE Error

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        Node* inter = new Node(-1);
        Node* interTail = inter;
        
        Node* ll1 = head1;
        
        while(ll1){
            Node* ll2 = head2;
            while(ll2){
                if(ll1->data==ll2->data){
                    interTail->next=ll1;
                    interTail=interTail->next;
                }
                ll2=ll2->next;
            }
            ll1=ll1->next;
        }
        interTail->next=NULL;
        
        head1=inter->next;
        
        return head1;
    }
};

// Approach 2: Using Map [TC: O(N+M)]

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        Node* temp1 = head1;
        Node* temp2 = head2;
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        
        unordered_map<int,bool> found;
        
        while(temp2){
            found[temp2->data]=true;
            temp2=temp2->next;
        }
        
        while(temp1){
            if(found[temp1->data]){
                tail->next=temp1;
                tail=tail->next;
            }
            temp1=temp1->next;
        }
        tail->next=NULL;
        return dummy->next;
    }
};