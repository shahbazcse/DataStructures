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
    
    if(first->data<=second->data){
         return sortLL(first,second);
    }
    else{
         return sortLL(second,first);
    }
}