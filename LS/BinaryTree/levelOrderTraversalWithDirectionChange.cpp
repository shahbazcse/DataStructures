// Link: https://www.geeksforgeeks.org/level-order-traversal-direction-change-every-two-levels/

// Approach: Iterative + Queue [TC: O(N) / SC: O(N)]

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node* left;
    int data;
    struct Node* right;
};

Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void modifiedLevelOrder(Node* root){
    if(root==NULL) return;
    
    queue<Node*> q;
    q.push(root);
    
    int flag = 0;
    int k = 2;
    
    while(!q.empty()){
        int cnt = q.size();
        vector<int> ds;
        
        for(int i=0; i<cnt; i++){
            Node* node = q.front();
            q.pop();
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            
            if(!flag){
                ds.push_back(node->data);
            }else{
                ds.insert(ds.begin(),node->data);
            }
        }
        for(auto it : ds) cout<<it<<" ";
        cout<<endl;
        
        k--;
        
        if(k==0){
            k=2;
            flag =!flag;
        }
    }
}

int main() {
    
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(1);
    root->right->left->left = newNode(4);
    root->right->left->right = newNode(2);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(2);
    root->left->right->left->left = newNode(16);
    root->left->right->left->right = newNode(17);
    root->right->left->right->left = newNode(18);
    root->right->right->left->right = newNode(19);
 
    modifiedLevelOrder(root);
 
    return 0;
}