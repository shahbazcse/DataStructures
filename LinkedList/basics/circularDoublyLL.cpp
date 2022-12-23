#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    // Constructor will be called every time a new Node is created
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    // Destructor will be called every time an existing Node is deleted
    ~Node(){
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
    }
};
// Insert

void insertNode(Node* &tail, int target, int data){
    // Empty List
    if(tail==NULL){
        Node* temp = new Node(data);
        tail = temp;
        temp->next=temp;
        temp->prev=temp;
        return;
    }
    else{
        Node* temp = tail;

        while(temp->data!=target){
            temp=temp->next;
        }

        Node* nodeToInsert = new Node(data);
        temp->prev->next = nodeToInsert;
        nodeToInsert->prev = temp->prev;
        nodeToInsert->next = temp;
        temp->prev = nodeToInsert;
        tail = nodeToInsert;
    }
}

// Delete
void deleteNode(Node* &tail, int target){
    if(tail == NULL){
        cout<<"Empty List"<<endl;
        return;
    }

    Node* prevNode = tail;
    Node* currentNode = prevNode->next;


    while(currentNode->data != target){
        prevNode=currentNode;
        currentNode=currentNode->next;
    }
    prevNode->next = currentNode->next;
    currentNode->next->prev = prevNode;
    
    // Delete tail node in only one node LL: Handle tail=NULL error

    // Delete tail node in more than 2 node LL
    if(tail=currentNode) tail = prevNode;

    currentNode->next = NULL;
    currentNode->prev = NULL;
    delete currentNode;
}

// Traverse
void printLL(Node* &tail){
    Node* temp = tail;

    if(tail == NULL){
        cout<<"Empty List"<<endl;
        return;
    }
    
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail);
    cout<<endl;
}

int main(){
    Node* tail = NULL;

    insertNode(tail,5,3);

    printLL(tail);

    insertNode(tail,3,5);

    printLL(tail);

    insertNode(tail,5,7);

    printLL(tail);

    insertNode(tail,7,9);

    printLL(tail);

    deleteNode(tail,5);

    printLL(tail);

    return 0;
}