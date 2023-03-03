#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

/*
                          1 -> root node
                         / \
     left child node <- 2   3 -> right child node
                         \
                          5 -> right child node of left parent node
*/

void main(){
    // Root node
    struct Node* root = new Node(1);

    // left child node
    root->left = new Node(2);
    // right child node
    root->right = new Node(3);

    // right child node of left parent node
    root->left->right = new Node(5);
}