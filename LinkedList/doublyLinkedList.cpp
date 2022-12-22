#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        // Constructor will be called every time a new Node is created
        Node(int data){
            this->data=data;
            this->next=NULL;
            this->prev=NULL;
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
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head=temp;
    }
}

void insertAtTail(Node* head, Node* &tail, int data)
{
    //Empty List
    if(head==NULL && tail==NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp->next = tail->next;
        temp->prev = tail;
        tail->next = temp;  
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* & tail, int position, int data)
{
    Node* temp  = head;
    int cnt=1;

    // Insert at Head
    if(position == 1){
        insertAtHead(head,tail,data);
        return;
    }

    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    // Insert at Tail
    if(temp->next == NULL){
        insertAtTail(head,tail,data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(Node* &head, Node* &tail, int position)
{
    // Delete first node
    if(position == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = head->next;
        temp->next=NULL;
        delete temp;
    }

    Node* temp = head;
    int cnt=1;
    
    while(temp){
        if(cnt==position-1){
            Node* currentNode = temp->next;
            temp->next = currentNode->next;

            // Delete last node
            if(temp->next==NULL) tail = temp; // Updating 'tail'
            else currentNode->next->prev = temp;
            
            currentNode->next = NULL;
            delete currentNode;
        }
        temp=temp->next;
        cnt++;
    }
}

// Calculating the length of LL by traversing the entire LL
void getLength(Node* &head){
    Node* temp = head;

    int cnt=0;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    cout<<"Length of LL: "<<cnt<<endl;
}

// Traversing the LL and printing all node data
void printLL(Node* &head){
    Node* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
        cout<<endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,11);

    insertAtHead(head,tail,13);

    insertAtHead(head,tail,8);

    insertAtTail(head,tail,6);

    printLL(head);

    insertAtPosition(head,tail,4,18);

    printLL(head);

    deleteNode(head,tail,5);

    printLL(head);
    getLength(head);

    cout<<"HEAD: "<<head->data<<endl;
    cout<<"TAIL: "<<tail->data<<endl;

    return 0;
}