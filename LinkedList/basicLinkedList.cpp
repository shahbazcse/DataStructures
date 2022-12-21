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

void insertAtHead(Node* &head, int data)
{
    Node* temp = new Node(data); // Creating a temp node
    temp->next = head;           // Storing address in 'head' into 'temp->next'
    head = temp;                 // Pointing 'head' to 'temp' (storing address of 'temp' in 'head')
}

void insertAtTail(Node* &tail, int data)
{
    Node* temp = new Node(data); // Creating a temp node
    tail->next = temp;           // Storing address of 'temp' in 'tail->next'
    tail = tail->next;           // Pointing 'tail' to address stored in 'tail->next' i.e. 'temp' node
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data)
{
    Node* temp = head;
    int cnt = 1;

    // Insert at Head
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    while (temp)
    {
        // Insert at Tail
        if (temp->next == NULL)
        {
            insertAtTail(tail, data);
            return;
        }
        if (cnt == position - 1)
        {
            Node* nodeToInsert = new Node(data);
            nodeToInsert->next = temp->next;
            temp->next = nodeToInsert;
        }
        temp = temp->next;
        cnt++;
    }
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
            if(temp->next==NULL) tail = temp; // Updating 'tail'
            currentNode->next = NULL;
            delete currentNode;
        }
        temp = temp -> next;
        cnt++;
    }
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
    // Creating a new node object
    Node* one = new Node(10);

    // Storing address of head/first node
    Node* head = one;
    Node* tail = one;

    // cout << one->data << endl; // Printing data value present in current node
    // cout << one->next << endl; // Printing address of next node present in current node

    insertAtHead(head, 12);

    // printLL(head);

    insertAtTail(tail, 5);

    printLL(head);

    insertAtPosition(head, tail, 4, 100);

    printLL(head);

    deleteNode(head,tail, 4);

    printLL(head);

    cout << "HEAD " << head->data << endl; // Check HEAD
    cout << "TAIL " << tail->data << endl; // Check TAIL

    return 0;
}