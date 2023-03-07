// Link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

// Approach 1: Iterative + Queue [TC: O(N) / SC: O(N)]

vector<int> leftView(Node *root)
{
    // create an empty vector to store the answer
    vector<int> ans;
    
    // return empty vector if tree is empty
    if(root==NULL) return ans;
        
    // create a queue to perform level order traversal
    queue<Node*> q;
    
    // push the root node into the queue
    q.push(root);
        
    // loop until queue is empty
    while(!q.empty()){
        // get the size of the queue for the current level
        int size = q.size();

        // keep track of the index of each node in the current level
        int index=0;
            
        while(size--){
            // get the front node of the queue
            Node* node = q.front();
            
            // remove the front node from the queue
            q.pop();
            
            // if it's the leftmost node of the current level, add it to the answer vector
            if(index==0) ans.push_back(node->data);
            
            // push the left child into the queue if it exists
            if(node->left) q.push(node->left);

            // push the right child into the queue if it exists
            if(node->right) q.push(node->right);
            index++; // increment the index for the next node in the current level
        }
    }
    return ans;
}

// Approach 2: Recursion [TC: O(N) / Aux. SC: O(Height)]

void solve(Node* root, vector<int> &ans,int level){
    if(root==NULL) return;
    
    // if it's the leftmost node of the current level, add it to the answer vector
    if(level==ans.size()) ans.push_back(root->data);
    
    if(root->left) solve(root->left,ans,level+1);
    if(root->right) solve(root->right,ans,level+1);
}

vector<int> leftView(Node *root)
{
   vector<int> ans;
   solve(root,ans,0);
   return ans;
}