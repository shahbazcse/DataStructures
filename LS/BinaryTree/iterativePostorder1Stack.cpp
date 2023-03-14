// Link: https://practice.geeksforgeeks.org/problems/postorder-traversal-iterative/1

// Approach 1: Iterative + 1 Stack [TC: O(N) / SC: O(N)]

class Solution{
    public:
    vector<int> postOrder(Node* node) {
        vector<int> post;
        if(node==NULL) return post;
        
        Node* curr = node;
        
        stack<Node*> st;
        
        while(curr || !st.empty()){
            // move to left node
            if(curr){
                st.push(curr);
                curr = curr->left;
            }else{
                // move to right node
                Node* top = st.top()->right;
                
                // check leaf node
                if(top==NULL){
                    top = st.top();
                    st.pop();
                    
                    post.push_back(top->data);
                    
                    // root node
                    while(!st.empty() && top == st.top()->right){
                        top = st.top();
                        st.pop();
                        
                        post.push_back(top->data);
                    }
                }else curr = top;
            }
        }
        return post;
    }
};

// Approach 2: Iterative + 1 Stack [TC: O(N) / SC: O(N)]

/*
    Intuition: Push directly root node two times while traversing to the left. 
              While popping if you find stack top() is same as root 
              then go for root->right else print root.
*/

class Solution{
    public:
    vector<int> postOrder(Node* node) {
        Node* curr = node;
        
        vector<int> postorder;
        
        if(curr==NULL) return postorder;
        
        stack<Node*> st;
        
        while(1){
            // move to left node
            while(curr){
                st.push(curr);
                st.push(curr);
                curr = curr->left;
            }
            
            if(st.empty()) break;
            
            curr = st.top();
            st.pop();
            
            // move to right node
            if(!st.empty() && st.top() == curr) curr = curr->right;
            else{
                // root node
                postorder.push_back(curr->data);
                curr = NULL;
            }
        }
        return postorder;
    }
};

// Approach 3: Iterative + 1 Stack + Hashing [TC: O(N) / SC: O(N)]

class Solution{
    public:
    vector<int> postOrder(Node* node) {
        vector<int> postorder;
        
        if(node==NULL) return postorder;
        
        unordered_map<Node*,int> visited;
        
        stack<Node*> st;
        st.push(node);
        
        while(!st.empty()){
            Node* curr = st.top();
            
            // mark visited
            visited[curr] = 1;
            
            // move to left child node
            if(curr->left && !visited[curr->left]){
                st.push(curr->left);
            }
            // move to right child node
            else if(curr->right && !visited[curr->right]){
                st.push(curr->right);
            }else{
                // visited node or leaf node
                postorder.push_back(curr->data);
                st.pop();
            }
        }
        return postorder;
    }
};