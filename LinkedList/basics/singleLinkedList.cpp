#include <iostream>
using namespace std;

// Creating node class
class Node
{
public:
    int data;
    Node* next;

    // Constructor will be called every time a new Node is created
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor will be called every time an existing Node is deleted
    ~Node()
    {
        if (this->next != NULL)
        {
            // Memory free
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(Node* &head, Node* &tail, int data)
{
    // Empty List
    if(head==NULL && tail==NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data); // Creating a temp node
        temp->next = head;           // Storing address present in 'head' into 'temp->next'
        head = temp;                 // Pointing 'head' to 'temp' (storing address of 'temp' in 'head')
    }
}

void insertAtTail(Node* &head, Node* &tail, int data)
{
    // Empty List
    if(head==NULL && tail==NULL){
        Node* temp = new Node(data);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp = new Node(data); // Creating a temp node
        temp->next=tail->next;       // Storing address present in tail->next(NULL) into temp->next
        tail->next = temp;           // Storing address of 'temp' in 'tail->next'
        tail = temp;                 // Updating tail
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data)
{
    Node* temp = head;
    int cnt = 1;

    // Insert at Head
    if (position == 1)
    {
        insertAtHead(head,tail, data);
        return;
    }

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // Insert at Tail
    if (temp->next == NULL)
    {
        insertAtTail(head,tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head, Node* &tail, int position)
{
    Node* temp = head;
    int cnt = 1;

    // Delete first node
    if (position == 1)
    {
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    while (temp)
    {
        if (cnt == position - 1)
        {
            Node* currentNode = temp->next;
            temp->next = currentNode->next;
            // Delete last node
            if(temp->next==NULL) tail = temp; // Updating 'tail'
            
            currentNode->next = NULL;
            delete currentNode;
        }
        temp = temp -> next;
        cnt++;
    }
}

// My approach
bool detectLoop(Node* &head){
    Node* temp = head;
    
    while(temp){
        if(temp->next==head) return true;
        temp=temp->next;
    }
    return false;
}

// Floyd's Cycle Detection Algorithm
bool hasCycle(Node *head) {
    Node* slow = head;
    Node* fast = head;

    while(slow && fast && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow) return 1;
    }
    return 0;
}

void printLL(Node* &head)
{
    Node* temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // // Creating a new node object
    // Node* one = new Node(10);

    // // Storing address of head/first node
    // Node* head = one;
    // Node* tail = one;

    // cout << one->data << endl; // Printing data value present in current node
    // cout << one->next << endl; // Printing address of next node present in current node

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail, 12);

    // printLL(head);

    insertAtTail(head,tail, 5);
    insertAtTail(head,tail, 7);

    printLL(head);

    insertAtPosition(head, tail, 3, 100);

    insertAtTail(head,tail, 28);

    deleteNode(head,tail, 1);

    printLL(head);

    if(detectLoop(tail)) cout<<"Is circular"<<endl;
    else cout<<"Is not circular"<<endl;

    // printLL(head);

    cout << "HEAD " << head->data << endl; // Check HEAD
    cout << "TAIL " << tail->data << endl; // Check TAIL

    return 0;
}