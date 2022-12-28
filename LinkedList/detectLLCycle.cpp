// Detect Loop in LL: Total 3 ways

    // Approach 1: Floyd's Cycle Detection Algorithm
    class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode* slow = head;
            ListNode* fast = head;

            while(slow && fast && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
                if(fast==slow) return 1;
            }
            return 0;
        }
    };

    // Approach 2: using Map for visited/non-visited nodes

    bool hasCycle(ListNode* head){
        if(head==NULL) return false;

        map<ListNode*, bool> visited;

        ListNode* temp = head;

        while(temp){
            // Loop present
            if(visited[temp]) return true;
            
            visited[temp] = true;
            temp = temp->next;
        }
        return false;
    }

// Find starting node of Loop in LL:

    class Solution {
    public:
        Node* findStartingNode(ListNode *head) {
            ListNode* slow = head;
            ListNode* fast = head;

            while(slow && fast && fast->next!=NULL){
                slow=slow->next; // At 1x speed
                fast=fast->next->next; // At 2x speed
                // Detect Loop
                if(fast==slow){
                    // Find starting node of Loop
                    Node* slow = head;
                    while(slow!=fast){
                        slow=slow->next; // At 1x speed
                        fast=fast->next; // At 1x speed
                    }
                    return slow;
                };
            }
            return NULL;
        }
    };

// Remove Loop from LL: Total 5 ways

    Node *removeLoop(Node *head){
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;        
    
        Node* slow = head;
        Node* fast = head;

        while(slow && fast && fast->next!=NULL){
            slow=slow->next; // At 1x speed
            fast=fast->next->next; // At 2x speed
            // Detect Loop
            if(fast==slow){
                // Find starting node of Loop
                Node* slow = head;
                Node* temp = head;
                while(slow!=fast){
                    slow=slow->next; // At 1x speed
                    temp = fast;
                    fast=fast->next; // At 1x speed
                }
                temp->next=NULL;
            };
        }
        return head;
    }
