// Link: https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

// Approach 1: Using Map [TC: O(N)]

class Solution
{
    public:
    Node *copyList(Node *head)
    {
        // Create Clone LL
        Node* temp = head;
        Node* clone = new Node(-1);
        Node* tail = clone;
        
        while(temp){
            Node* copy = new Node(temp->data);
            tail->next=copy;
            tail=tail->next;
            temp=temp->next;
        }
        tail->next=NULL;
        
        // Map Original and Clone LL
        unordered_map<Node*,Node*> mapLL;
        
        Node* ogNode = head;
        Node* cloneNode = clone->next;
        
        while(ogNode){
            mapLL[ogNode] = cloneNode;
            ogNode=ogNode->next;
            cloneNode=cloneNode->next;
        }
        
        // Copy random pointer using Map
        ogNode = head;
        cloneNode = clone->next;
        
        while(ogNode){
            cloneNode->arb=mapLL[ogNode->arb];
            ogNode=ogNode->next;
            cloneNode=cloneNode->next;
        }

        return clone->next;
    }

};

// Approach 2: Using LL Pointer in constant space [TC: O(N) / SV: O(1)]

class Solution
{
    public:
    Node *copyList(Node *head)
    {
        // Create Clone LL
        Node* temp = head;
        Node* clone = new Node(-1);
        Node* tail = clone;
        
        while(temp){
            Node* copy = new Node(temp->data);
            tail->next=copy;
            tail=tail->next;
            temp=temp->next;
        }
        tail->next=NULL;
        
        // Insert Clone LL's nodes between Original LL's nodes
        
        Node* ogNode = head;
        Node* cloneNode = clone->next;
        Node* forward = NULL;
        
        while(ogNode && cloneNode){
            forward = ogNode->next;
            ogNode->next= cloneNode;
            ogNode=forward;
            
            forward=cloneNode->next;
            cloneNode->next=ogNode;
            cloneNode=forward;
        }
        
        // Copy random pointer
        temp = head;
        
        while(temp){
            if(temp->next){
                if(temp->arb) temp->next->arb = temp->arb->next;
                else temp->next->arb = NULL;
            }
            temp=temp->next->next;
        }
        
        // Revert changes
        ogNode = head;
        cloneNode = clone->next;

        while(ogNode && cloneNode){
            ogNode->next = cloneNode->next;
            ogNode=ogNode->next;
            
            if(ogNode) cloneNode->next = ogNode->next;
            cloneNode=cloneNode->next;
        }
        
        return clone->next;
    }
};