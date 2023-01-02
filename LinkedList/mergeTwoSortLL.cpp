// Platform: Leetcode

class Solution {
public:
    ListNode* mergeLL(ListNode* list1, ListNode* list2){
        if(list1->next==NULL){
            list1->next=list2;
            return list1;
        }

        ListNode* curr = list1;
        ListNode* next1 = list1->next;
        ListNode* temp = list2;
        ListNode* forward = NULL;

        while(curr && temp){
            if((curr->val<=temp->val) && (temp->val<=next1->val)){
                forward=temp->next;
                curr->next=temp;
                temp->next=next1;

                curr = temp;
                temp = forward;
            }else{
                curr=next1;
                next1=next1->next;
                if(!next1){
                    curr->next=temp;
                    return list1;
                }
            }
        }
        return list1;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        if(list1->val<=list2->val){
            return mergeLL(list1,list2);
        }
        else{
            return mergeLL(list2,list1); 
        }
    }
};

// Platform: CodeStudio

Node<int>* sortLL(Node<int>* first, Node<int>* second){
    
    // If first LL has only one node
    if(first->next == NULL){
        first->next = second;
        return first;
    }
    
    Node<int>* prevNode = first;
    Node<int>* currentNode = first->next;
    Node<int>* temp = second;
    Node<int>* forward = temp->next;
    
    while(currentNode && temp){
        // Adding nodes from second LL between nodes in first LL
        if((prevNode->data <= temp->data) && (temp->data <= currentNode->data)){
            forward = temp->next;
            prevNode->next = temp;
            temp->next=currentNode;
            
            prevNode = temp;
            temp = forward;
        }else{
            // Moving ahead in first LL if no nodes in second LL lies in range
            prevNode = currentNode;
            currentNode = currentNode->next;
            
            // If first LL traversal reaches NULL
            if(!currentNode){
                prevNode->next = temp;
                return first;
            }
        }
    }
    return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(!first) return second;
    if(!second) return first;
    
    /*
    Checking for LL having smaller head node, 
    that LL will have nodes inserted in it from the other LL
    */
    if(first->data<=second->data){
         return sortLL(first,second);
    }
    else{
         return sortLL(second,first);
    }
}