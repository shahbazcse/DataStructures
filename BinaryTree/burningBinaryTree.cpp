// Link: https://practice.geeksforgeeks.org/problems/burning-tree/1

// Approach: BFS + Queue + Map [TC: O(N) / SC: O(N)]

class Solution {
  public:
    int findMaxDistance(map<Node*,Node*> &mpp, Node* start){
        // queue to store the current node to traverse radially upwards and downwards
        queue<Node*> q;
        q.push(start);
        
        // map to track burned nodes
        map<Node*,int> visited;
        visited[start] = 1;

        int maxi = 0; // tracking time to burn the nodes
        
        while(!q.empty()){
            int size = q.size(); // size of nodes in the current level

            int burn = 0; // tracking if any node from current node is burned or not
            
            // Traversal to burn the nodes present upwards and downwards
            for(int i=0; i<size; i++){
                Node* node = q.front(); // take current node
                q.pop();
                
                // if left child node of the current node exists, burn it, and mark it as burned and push the left child for burning further nodes in the tree
                if(node->left && !visited[node->left]){
                    burn = 1;
                    visited[node->left] = 1;
                    q.push(node->left);
                }
                
                // if right child node of the current node exists, burn it, and mark it as burned and push the right child for burning further nodes in the tree
                if(node->right && !visited[node->right]){
                    burn = 1;
                    visited[node->right] = 1;
                    q.push(node->right);
                }
                
                // if parent node of the current node exists, burn it, and mark it as burned and push the node for burning further nodes in the tree
                if(mpp[node] && !visited[mpp[node]]){
                    burn = 1;
                    visited[mpp[node]] = 1;
                    q.push(mpp[node]);
                }
            }
            if(burn) maxi++; // if any single node is burned from the current node, increase time by 1
        }
        return maxi; // return total time taken to burn all nodes in the tree
    }
    
    Node* mapParents(Node* root, map<Node*,Node*> &mpp, int target){
        // queue to store the node in the current level
        queue<Node*> q;
        q.push(root);
        
        // starting node address to be returned
        Node* res;
        
        // BFS traversal to map parent-child nodes at each level
        while(!q.empty()){
            Node* node = q.front();
            if(node->data == target) res = node; // if the target value is found, store the address of the node
            q.pop();
            
            // if the left child node exists, map current node as parent to the left child node, and push the child for further level traversal
            if(node->left){
                mpp[node->left] = node;
                q.push(node->left);
            }
            
            // if the right child node exists, map current node as parent to the right child node, and push the child for further level traversal
            if(node->right){
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
        return res; // return the starting node address to burn the tree
    }
    
    int minTime(Node* root, int target) 
    {
        // map parent-child nodes relationship and get the address of starting node of burning the tree by passing the target value
        map<Node*,Node*> mpp;
        Node* start = mapParents(root,mpp,target);

        // get the time to burn the tree from start node, by using BFS traversal and mpp to traverse back to parent node
        int maxi = findMaxDistance(mpp,start);
        return maxi;
    }
};