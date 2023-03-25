// Link: https://www.codingninjas.com/codestudio/problems/convert-bst-to-min-heap_920498

// Approach: Recursion + Inorder Traversal [TC: O(N) / SC: O(N)]

void inorderTraversal(BinaryTreeNode* root, vector<BinaryTreeNode*> &inorder){
	if(root==NULL) return;

	inorderTraversal(root->left,inorder);
	inorder.push_back(root);
	inorderTraversal(root->right,inorder);
}

BinaryTreeNode* buildMinHeap(vector<BinaryTreeNode*> &inorder, int &idx){
	// return when no nodes are present in inorder array
    if(idx == inorder.size()) return NULL;

    // create root with using first root in inorder array and move idx ahead by 1
	BinaryTreeNode* root = inorder[idx++];

    // make recursive call for left child node
	root->left = buildMinHeap(inorder,idx);

    // make recursive call for right child node
	root->right = buildMinHeap(inorder,idx);

	return root;	
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
    // Find Inorder Traversal of input BST
	vector<BinaryTreeNode*> inorder;
	inorderTraversal(root,inorder);

    // keep track of inorder array index while creating Min Heap
	int idx=0;

	return buildMinHeap(inorder,idx);
}