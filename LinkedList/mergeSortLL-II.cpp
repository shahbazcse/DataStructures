// Link: https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

// Approach: [TC: O(nlogn)]

class Solution{
  public:
    Node* findMid(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    Node* mergeLL(Node* left, Node* right){
        if(!left) return right;
        if(!right) return left;
        
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        while(left && right){
            if(left->data < right->data){
                temp->next=left;
                temp=temp->next;
                left=left->next;
            }else{
                temp->next=right;
                temp=temp->next;
                right=right->next;
            }
        }
        
        if(left){
            temp->next=left;
        }
        
        if(right){
            temp->next=right;
        }

        return ans->next;
    }
    
    Node* mergeSort(Node* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        Node* mid = findMid(head);
        
        Node* left = head;
        Node* right = mid->next;
        mid->next=NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        return mergeLL(left,right);
    }
};