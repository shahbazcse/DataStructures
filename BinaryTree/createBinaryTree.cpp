// Link: https://practice.geeksforgeeks.org/problems/binary-tree-representation/1

// Approach 1: Constant space and time complexity [TC: O(1) / SC: O(1)]

class Solution{
public:

    void create_tree(node* root0, vector<int> &vec){
        
        node* root1 = newNode(vec[1]);
        node* root2 = newNode(vec[2]);
        node* root3 = newNode(vec[3]);
        node* root4 = newNode(vec[4]);
        node* root5 = newNode(vec[5]);
        node* root6 = newNode(vec[6]);
        
        root0->left = root1;
        root0->right = root2;
        
        root1->left = root3;
        root1->right = root4;
        
        root2->left = root5;
        root2->right = root6;
        
    }
};

// Approach 2: Queue [TC: O(N) / SC: O(N)]

class Solution{
public:
    void create_tree(node* root0, vector<int> &vec){
        
        // Create a queue of node pointers and push the root node to it
        queue<node*> q;
        q.push(root0);
        
        // Get the size of the vector and initialize a counter variable i to 1
        int n = vec.size();
        int i = 1;
        
        // Loop until i is less than n
        while (i < n) {
            // Get the front node from the queue and remove it
            node* curr = q.front();
            q.pop();
            
            // Create a new left child node with the value from vec[i] and push it to the queue
            curr->left = newNode(vec[i]);
            q.push(curr->left);
            i++;
            
            // Create a new right child node with the value from vec[i+1] and push it to the queue
            curr->right = newNode(vec[i]);
            q.push(curr->right);
            i++;
        }
    }
};