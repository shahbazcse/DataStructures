// Link: https://leetcode.com/problems/clone-graph/

// Approach: DFS + HashMap [TC: O(V+E) / SC: O(V)]

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        if(!mp.count(node)){
            // create copy node
            mp[node] = new Node(node->val);
            // create copy neighbors
            for(auto it : node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(it)); // make recursive call for neighbor nodes
            }
        }
        return mp[node];
    }
};