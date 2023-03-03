// Link: https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1

// Approach 1: Iterative + Queue [TC: O(N) / SC: O(N)]

// Function to return a list containing the level order traversal in spiral form.

vector<int> findSpiral(Node *root)
{
    vector<int> ans; // Create an empty vector to store the nodes in spiral order.
    
    if(root==NULL) return ans;   // If the root is NULL, return the empty vector.
    
    queue<Node*> q;  // Create a queue of Node pointers.
    q.push(root);    // Push the root node into the queue.
    
    int k=0;   // Create a variable to keep track of the level number.
    while(!q.empty()){    // While the queue is not empty,
        vector<int> level;   // Create an empty vector to store the nodes at the current level.
        int nodeCount = q.size();  // Get the number of nodes in the current level.
        
        while(nodeCount--){    // Process all the nodes in the current level.
            Node* front = q.front();   // Get the first node in the queue.
            
            q.pop();   // Pop the first node from the queue.
            
            if(front->left) q.push(front->left);  // If the left child of the current node is not NULL, push it into the queue.
            if(front->right) q.push(front->right); // If the right child of the current node is not NULL, push it into the queue.
            
            level.push_back(front->data);   // Push the data of the current node into the level vector.
        }
        
        if(k%2==0) reverse(level.begin(),level.end());  // If the level number is even, reverse the level vector to get the nodes in right to left order.
        
        for(auto it:level) ans.push_back(it);   // Push the nodes in the level vector into the answer vector.
        
        k++;   // Increment the level number.
    }
    return ans;  // Return the answer vector.
}

// Approach 2: Recursion [TC: O(N) / SC: O(N)]

// Function to return a list containing the level order traversal in spiral form.
void solve(Node* root, vector<vector<int>> &ans, int level){

    // If the current node is NULL, then return from the function.
    if(root==NULL) return;
    
    // If the current level is equal to the size of the answer vector, then add a new empty vector to it.
    if(level == ans.size()) ans.push_back({});
    
    // If the current level is even, then add the data of the nodes from left to right in level vector of the answer vector.
    if(level%2 == 0) ans[level].insert(ans[level].begin(),root->data);

    // If the current level is odd, then add the data of the nodes from right to left in level vector of the answer vector.
    if(level%2 != 0) ans[level].push_back(root->data);
    
    // Recursively call the solve function for the left child of the current node, passing the same answer vector and the next level.
    solve(root->left,ans,level+1);
    
    // Recursively call the solve function for the right child of the current node, passing the same answer vector and the next level.
    solve(root->right,ans,level+1);
}

// This function takes a pointer to the root of a binary tree, and returns a vector containing the data of all the nodes in the tree in spiral order.
vector<int> findSpiral(Node *root)
{
    // Declare a vector of vectors to store the answer, and a vector to store the flattened answer.
    vector<vector<int>> ans;
    vector<int> ds;
    
    // Call the solve function with the root of the tree, the answer vector, and the starting level (0).
    solve(root,ans,0);
    
    // Flatten the answer vector by iterating over each level's vector and appending its elements to the result vector.
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            ds.push_back(ans[i][j]);
        }
    }
    
    // Return the flattened vector.
    return ds;
}