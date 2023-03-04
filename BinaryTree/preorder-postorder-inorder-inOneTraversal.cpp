// Link: https://www.codingninjas.com/codestudio/problems/981269

// Approach 1: Iterative + Stack [TC: O(N) / SC: O(N)]

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Initialize a stack with the root node and the pre-order traversal order
    stack<pair<BinaryTreeNode<int>*,int>> st;
    st.push({root,1});

    // Initialize vectors to store the pre-order, in-order, and post-order traversals
    vector<vector<int>> ans;
    vector<int> preOrder, inOrder, postOrder;

    // Check if the tree is empty
    if(root==NULL) return ans;

    // While the stack is not empty, pop nodes from the stack and process them
    while(!st.empty()){
        // Get the top node to process from the stack
        auto it = st.top();
        st.pop();

        // If the node is being processed in pre-order, add it to the pre-order vector 
        if(it.second == 1){
            preOrder.push_back(it.first->data);
            it.second++; // add node with in-order traversal order in the stack
            st.push(it);

            if(it.first->left != NULL) st.push({it.first->left,1}); // add left child with pre-order traversal order onto the stack

        // If the node is being processed in in-order, add it to the in-order vector
        }else if(it.second == 2){
            inOrder.push_back(it.first->data);
            it.second++; // add node with post-order traversal order in the stack
            st.push(it);

            if(it.first->right != NULL) st.push({it.first->right,1}); // add right child with pre-order traversal order onto the stack

        // If the node is being processed in post-order, add it to the post-order vector
        }else{
            postOrder.push_back(it.first->data);
        }
    }

    // Add the pre-order, in-order, and post-order vectors to the answer vector
    ans.push_back(inOrder);
    ans.push_back(preOrder);
    ans.push_back(postOrder);

    // Return the answer vector
    return ans;
}

// Approach 2: Recursion [TC: O(N) / SC: O(N)]

void trav(BinaryTreeNode<int> *root, vector<int> &in, vector<int> &pre, vector<int> &post){
    // Base case: if root is NULL, return
    if(!root) return;
    
    // Add root's value to pre-order vector
    pre.push_back(root->data);
    
    // Traverse left subtree recursively
    trav(root->left, in, pre, post);
    
    // Add root's value to in-order vector
    in.push_back(root->data);
    
    // Traverse right subtree recursively
    trav(root->right, in, pre, post);
    
    // Add root's value to post-order vector
    post.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Initialize empty vectors for in-order, pre-order, and post-order
    vector<int> in,pre,post;

    // Traverse the tree recursively to fill the vectors
    trav(root,in,pre,post);

    // Initialize a vector of vectors to store the traversals
    vector<vector<int>> ans;
    
    // Add in-order, pre-order, and post-order vectors to ans vector in the appropriate order
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    
    // Return the vector of vectors containing the traversals
    return ans;
}