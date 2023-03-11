// Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

// Approach: Iterative + Queue + String [TC: O(N) / SC: O(N)]

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";

        string s;

        queue<TreeNode*> q;
        q.push(root);

        // BFS traversal to convert Binary Tree into String
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node==NULL) s += "#,";
            else s += to_string(node->val) + ',';

            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        
        // read about stringstream and getline
        stringstream s(data);
        string str;
        getline(s,str,',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        // construct binary tree
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            // append left child node
            getline(s,str,',');
            if(str=="#"){
                node->left = NULL;
            }else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            
            // append right child node
            getline(s,str,',');
            if(str=="#"){
                node->right = NULL;
            }else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};