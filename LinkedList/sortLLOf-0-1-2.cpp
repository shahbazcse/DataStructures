// Approach 1: By using dummy nodes based on 0s, 1s, and 2s, then merging them in sorted order

Node* sortList(Node *head)
{
    Node* temp = head;
    
    // Creating dummy nodes
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    // Creating separate LL for 0s, 1s, and 2s
    while(temp){
        if(temp->data==0){
            zeroTail->next=temp;
            zeroTail=zeroTail->next;
        }else if(temp->data==1){
            oneTail->next=temp;
            oneTail=oneTail->next;
        }else if(temp->data==2){
            twoTail->next=temp;
            twoTail=twoTail->next;
        }
        
        temp=temp->next;
    }
    
    // Merging all LL in sorted order while checking if 0,1,2 exists
    if(oneHead->next){
        zeroTail->next = oneHead->next;
        oneTail->next = twoHead->next;
    }else{
        zeroTail->next = twoHead->next;
    }
    twoTail->next = NULL;
    
    // Pointing to head
    head = zeroHead->next;
    
    // Deleting dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}

// Approach 2: By replacing values on nodes based on count of 0s,1s, and 2s

Node* sortList(Node *head)
{
    Node* temp = head;
    
    int zeroCount=0;
    int oneCount=0;
    int twoCount=0;
    
    // Counting occurences of 0s, 1s, and 2s
    while(temp){
        if(temp->data==0){
            zeroCount++;
        }else if(temp->data==1){
            oneCount++;
        }else if(temp->data==2){
            twoCount++;
        }
        
        temp=temp->next;
    }
    
    temp = head;
    
    // Replacing values on main LL based on count of 0s, 1s, and 2s
    while(temp){
        if(zeroCount!=0){
            temp->data=0;
            zeroCount--;
        }else if(oneCount!=0){
            temp->data=1;
            oneCount--;
        }else if(twoCount!=0){
            temp->data=2;
            twoCount--;
        }
        
        temp=temp->next;
    }
    
    return head;
}