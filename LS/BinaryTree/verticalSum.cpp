// Link: https://practice.geeksforgeeks.org/problems/vertical-sum/1

// Approach: Iterative BFS + Map + Queue [TC: O(NLogN) / SC: O(N)]

class Solution {
public:
    vector<int> verticalSum(Node *root) {
        // Initialize an empty vector called ans to store the vertical sums
        vector<int> ans;
        
        // Initialize an empty map called nodes to keep track of the sum of nodes at each vertical level of the tree
        map<int,int> nodes;
        
        // Initialize a queue called todo to perform a breadth-first search on the tree
        queue<pair<Node*,int>> todo;
        
        // Push the root node and its vertical level (which is 0) onto the queue
        todo.push({root,0});
        
        // Continue iterating through the queue until it is empty
        while(!todo.empty()){
            // Get the next pair of node and vertical level from the front of the queue
            auto p = todo.front();
            todo.pop();
            
            Node* node = p.first;
            
            int i = p.second;
            
            // Add the node's data to the sum of nodes at its vertical level in the map
            nodes[i] += node->data;
            
            // If the node has a left child, add it and its vertical level to the queue
            if(node->left) todo.push({node->left,i-1});
            
            // If the node has a right child, add it and its vertical level to the queue
            if(node->right) todo.push({node->right,i+1});
        }
        // Iterate through the map and append the sum of nodes at each vertical level to the ans vector
        for(auto it : nodes){
            ans.push_back(it.second);
        }
        // Return the ans vector containing the vertical sums
        return ans;
    }
};