// Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// Approach: Recursion + BFS + Queue + Unordered Map [TC: O(N) / SC: O(N)]

class Solution {
public:
    // A helper function that fills a map with parent-child relationships for each node in the tree
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent_track, TreeNode* target){
        // Create a queue for a BFS traversal of the tree starting from the root
        queue<TreeNode*> q;
        q.push(root);

        // Traverse the tree using BFS
        while(!q.empty()){
            // Get the current node and remove it from the queue
            TreeNode* current = q.front();
            q.pop();

            // Add the left child of the current node to the queue and set its parent in the map
            if(current->left){
                parent_track[current->left] = current;
                q.push(current->left);
            }

            // Add the right child of the current node to the queue and set its parent in the map
            if(current->right){
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

    // The main function that finds all nodes at a distance K from the target node
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Create a map to track parent-child relationships and call the helper function to fill it
        unordered_map<TreeNode*,TreeNode*> parent_track;
        markParents(root,parent_track,target);

        // Create a map to track visited nodes and a queue for a BFS traversal starting from the target node
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        
        // Keep track of the current level of the BFS traversal
        int curr_level = 0;

        // Traverse the tree using BFS
        while(!q.empty()){
            // Get the number of nodes in the current level of the BFS traversal
            int size = q.size();

            // If we have reached the target level, break out of the loop
            if(curr_level++ == k) break;

            // Traverse all nodes in the current level of the BFS traversal
            for(int i=0; i<size; i++){
                // Get the current node and remove it from the queue
                TreeNode* current = q.front();
                q.pop();

                // Add the left child of the current node to the queue if it is unvisited
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true; // mark the left child visited
                }

                // Add the right child of the current node to the queue if it is unvisited
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true; // mark the right child visited
                }

                // Add the parent of the current node to the queue if it is unvisited
                if(parent_track[current] && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true; // mark the parent visited
                }
            }
        }

        // Collect all nodes at the target level and return them
        vector<int> ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};