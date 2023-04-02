// Link: https://www.geeksforgeeks.org/convert-binary-tree-threaded-binary-tree-set-2-efficient/

// Approach: Iterative [TC: O(N) / SC: O(1)]

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    bool isThreaded; // to check for threaded nodes
    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// creating a threaded BT
Node* createThreadedBT(Node* root){
    if(root==NULL) return NULL;
    
    // if current node is leaf node, return current node
    if(!root->left && !root->right) return root;
    
    // if left child of current node exists, move to ahead to the left child
    if(root->left){
        // recursive call for left child until we reach the leaf node, then store it in temp node
        Node* temp = createThreadedBT(root->left);
        // point right child of temp to root (threading)
        temp->right = root;
        // mark true after threading the node
        temp->isThreaded = true;
    }
    // if right child of current node exists, move to ahead to the right child
    if(root->right) return createThreadedBT(root->right);
    // if right child is absent, then we can't move to right childs' path, so return current node
    else return root;
}

// moving to the left most node from root
Node* leftMost(Node* root){
    if(root==NULL) return NULL;
    while(root->left){
        root = root->left;
    }
    return root;
}

// inorder traversal of threaded BT
void inorder(Node* root){
    if(root==NULL) return;
    
    // move to the left most node of the root
    Node* curr = leftMost(root);
    
    // start traversing from the left most node
    while(curr){
        cout<<curr->data<<" "; // visit node
        
        // if node is threaded, then move to it's thread direction i.e right path
        if(curr->isThreaded) curr = curr->right;
        // if node is not threaded, then move to right child and find the left most node
        else curr = leftMost(curr->right);
    }
}

int main() {
    /*       1
            / \
           2   3
          / \ / \
         4  5 6  7   */
    
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    createThreadedBT(root);
 
    cout << "Inorder traversal of created "
            "threaded tree is\n";
    inorder(root);

    return 0;
}