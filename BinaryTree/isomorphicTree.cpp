// Link: https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1

// Approach: Recursion [TC: O(min(N,M)) / SC: O(min(N,M))]

class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        // if both root are NULL, then both are isomorphic, return true
        if(root1==NULL && root2==NULL) return true;
        
        // if one of them is NULL and the other is not NULL, then both are not isomorphic, return false
        if(root1==NULL || root2==NULL) return false;
        
        // if values of both nodes are not equal, then both are not isomorphic
        if(root1->data != root2->data) return false;
        
        // cases to check: 1. when the nodes are not flipped
        //                 2. when the nodes are flipped
        return (
                isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right) || 
                isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left)
                );
    }
};