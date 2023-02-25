// Link: https://www.geeksforgeeks.org/print-alternate-nodes-linked-list-using-recursion/

// Approach: Recursion [TC: O(N) / SC: O(1)]

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        struct Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void insertAtHead(Node* &head, int data)
{
    // Empty List
    if(head==NULL){
        Node* temp = new Node(data);
        head = temp;
    }
    else{
        Node* temp = new Node(data); // Creating a temp node
        temp->next = head;           // Storing address present in 'head' into 'temp->next'
        head = temp;                 // Pointing 'head' to 'temp' (storing address of 'temp' in 'head)
    }
}

// print alternate nodes
void printAlternate(Node* head){
    if(!head) return;
    cout<<head->data<<" ";
    if(head->next) printAlternate(head->next->next);
    else return;
}

int main() {
    // Start with the empty list
    Node* head = NULL;
 
    // construct below list
    // 1->2->3->4->5->6->7->8->9->10
 
    insertAtHead(head,10);
    insertAtHead(head,9);
    insertAtHead(head,8);
    insertAtHead(head,7);
    insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
 
    printAlternate(head);
 
    return 0;
}