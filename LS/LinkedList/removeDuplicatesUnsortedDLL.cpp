// Link: https://www.geeksforgeeks.org/remove-duplicates-unsorted-doubly-linked-list/

// Approach 1: Brute Force [TC: O(N^2) / SC: O(1)]

void removeDuplicates(struct Node** head_ref)
{
	// if DLL is empty or if it contains only
	// a single node
	if ((*head_ref) == NULL ||
		(*head_ref)->next == NULL)
		return;

	struct Node* temp = *head_ref;
  	
  	while(temp){
      	Node* curr = temp->next;
      	while(curr){
        	if(curr->data == temp->data){
                Node* forward = curr->next;

                curr->prev->next=curr->next;
                if(curr->next) curr->next->prev=curr->prev;
              
              	curr->next=NULL;
              	curr->prev=NULL;
                delete curr;
              	
                curr=forward;
            }else curr=curr->next;

        }
      temp=temp->next;
    }
}

// Approach 2: Hashing [TC: O(N) / SC: O(N)]

void removeDuplicates(struct Node** head_ref)
{
	// if doubly linked list is empty
	if ((*head_ref) == NULL)
		return;
        
	unordered_set<int> S;

	struct Node* curr = *head_ref;

    while(curr){
        if(S.find(curr->data)!=S.end()){
            Node* forward = curr->next;

            curr->prev->next=curr->next;
            if(curr->next) curr->next->prev=curr->prev;
              
            curr->next=NULL;
            curr->prev=NULL;
            delete curr;
              	
            curr=forward;
        }else{
            S.insert(curr->data);
            curr=curr->next;
        }
    }
}

// Approach 3: Merge Sort + Remove Duplicates [TC: O(NLogN) / SC: O(1)]