DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* currentNode = llist;
    DoublyLinkedListNode* prevNode = NULL;
    DoublyLinkedListNode* forward = NULL;
    
    while(currentNode){
        forward = currentNode->next;
        currentNode->next = prevNode;
        currentNode->prev = forward;
        prevNode = currentNode;
        currentNode = forward;
    }
    return prevNode;
}