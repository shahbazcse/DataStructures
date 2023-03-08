// Link: https://www.codingninjas.com/codestudio/problems/path-in-a-tree_3843990

// Approach: Recursion [TC: O(N) / SC: O(Height)]

// This is the helper function that recursively traverses the tree and finds the path from the root to the node with value 'x'.
bool getPath(TreeNode<int>* root, int x, vector<int> &ans){
	if(root==NULL) return false; // If the current node is NULL, return false.

	ans.push_back(root->data); // Add the value of the current node to the vector 'ans'.

	if(root->data==x) return true; // If the current node has value 'x', we have found the path, so return true.

    // Recursively call the function on the left and right subtrees of the current node.
    // If either of the recursive calls returns true, it means that we have found the node with value 'x' in the subtree,
    // so we return true to indicate that we have found the path.
	if(getPath(root->left,x,ans) || getPath(root->right,x,ans)) return true;

	ans.pop_back(); // If the function reaches this point, it means that the current node does not belong to the path to the node with value 'x',
                    // so we remove it from the vector 'ans' and return false to continue searching for the node in the remaining subtrees.

	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans; // Initialize an empty vector 'ans' that will store the path from the root to the node with value 'x'.
	if(root==NULL) return ans; // If the tree is empty, return the empty vector.

    // Call the helper function 'getPath' to traverse the tree and find the path from the root to the node with value 'x'.
	getPath(root,x,ans);

	return ans;
}