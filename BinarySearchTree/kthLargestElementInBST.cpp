// Link: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

// Approach: Recursion [TC: O(N) / SC: O(N)]

class Solution
{
    public:
    void countNodes(Node* root, int &cnt){
        if(root==NULL) return;
        
        countNodes(root->left,cnt);
        cnt++;
        countNodes(root->right,cnt);
    }

    void helper(Node* root, int &K, int &ans){
        if(root==NULL) return;
        
        helper(root->left,K,ans);
        
        K--;
        if(K==0){
            ans = root->data;
            return;
        }
        
        helper(root->right,K,ans);
    }
    
    int kthLargest(Node *root, int K)
    {
        int cnt=0;
        
        countNodes(root,cnt);
        
        // kth largest node = Total nodes - kth smallest node + 1
        K=cnt-K+1;
        
        int ans=0;
        
        helper(root,K,ans);
        
        return ans;
    }
};