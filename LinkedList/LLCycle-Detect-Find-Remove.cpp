// Detect Cycle/Loop in LL:

    // Link: https://leetcode.com/problems/linked-list-cycle/

    // Approach 1: Floyd's Cycle Detection Algorithm [TC: O(N)]
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

    // Approach 2: using Map for visited/non-visited nodes [TC: O(N)]

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

// Find starting node of Cycle/Loop in LL:

    // Link: https://leetcode.com/problems/linked-list-cycle-ii/

    // Approach: [TC: O(N^2)]

    class Solution {
    public:
        ListNode* detectCycle(ListNode *head) {
            ListNode* slow = head;
            ListNode* fast = head;

            while(slow && fast && fast->next!=NULL){
                slow=slow->next; // At 1x speed
                fast=fast->next->next; // At 2x speed
                // Detect Loop
                if(fast==slow){
                    // Find starting node of Loop
                    ListNode* slow = head;
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

// Remove Cycle/Loop from LL:

    // Link: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

    // Approach: [TC: O(N)]

    class Solution
    {
        public:
        //Function to remove a loop in the linked list.
        Node* isLoop(Node* head){
            Node* slow = head;
            Node* fast = head;
            
            while(slow && fast && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
                if(slow==fast){
                    return fast;
                }
            }
            return NULL;
        }
        void removeLoop(Node* head)
        {
            if(!isLoop(head)) return;
            
            Node* fast = isLoop(head);
            Node* slow = head;
            
            // If LL is Circular
            if(fast==head){
                while(fast->next!=head){
                    fast=fast->next;
                }
                fast->next=NULL;
                return;
            }
            
            while(fast->next!=slow->next){
                fast=fast->next;
                slow=slow->next;
            }
            fast->next=NULL;
            return;
        }
    };
