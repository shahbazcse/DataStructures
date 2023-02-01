// Approach: Recursion + Backtracking [TC: O(N) / SC: O(1)]

void helper(Node* head){
    // base case
    if(head==NULL) return;
    
    // recursive call
    helper(head->next);
    // backtracking after executing recursive call
    
    // printing current value in node after backtracking
    cout<<head->data<<" ";
}

int main() {
    Node* head = new Node(1);
    Node* temp = head;
    
    int i=2;
    while(temp && i<=5){
        Node* newNode = new Node(i);
        temp->next=newNode;
        temp=temp->next;
        i++;
    }
    temp->next=NULL;
    
    temp=head;
    
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
    helper(head); // calling recursive function
    cout<<endl;

    return 0;
}