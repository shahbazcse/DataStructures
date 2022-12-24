#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        // Constructor will be called every time a new Node is created
        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        // Destructor will be called every time an existing Node is deleted
        ~Node(){
            if(this->next != NULL){
                // Memory free
                delete next;
                next = NULL;
            }
        }
};

void insertNode(Node* &tail, int target, int data){
    // Empty List
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        temp->next = temp;
    }
    else{
        Node* temp = tail;

        while(temp->data != target){
            temp=temp->next;
        }

        Node* nodeToInsert = new Node(data);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }

}

void deleteNode(Node* &tail, int target){
    if(tail == NULL){
        cout<<"Empty List"<<endl;
        return;
    }

    Node* prevNode = tail;
    Node* currentNode = prevNode->next;

    while(currentNode->data!=target){
        prevNode=currentNode;
        currentNode=currentNode->next;
    }
    prevNode->next = currentNode->next;

    // // Delete tail node in only one node LL
    // if(currentNode = prevNode) tail = NULL;
    // Delete tail node in more than 2 node LL
    if(tail = currentNode) tail = prevNode;
    
    currentNode->next = NULL;
    delete currentNode;
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

void printLL(Node* &tail){
    Node* temp = tail;

    if(tail == NULL){
        cout<<"Empty List"<<endl;
        return;
    }

    do{       
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=tail);
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

    deleteNode(tail, 9);

    printLL(tail);

    if(hasCycle(tail)) cout<<"Is circular"<<endl;
    else cout<<"Is not circular"<<endl;

    return 0;
}