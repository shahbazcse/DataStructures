// Link: https://www.codingninjas.com/codestudio/problems/evaluate-expression-tree_975484

// Approach: Recursion [TC: O(N) / SC: O(N)]

int evaluateExpression(BinaryTreeNode<string> *root) 
{
	if(root==NULL) return 0;

	if(!root->left && !root->right) return stoi(root->data);

	int left = evaluateExpression(root->left);
	int right = evaluateExpression(root->right);

	if(root->data == "+"){
		return left+right;
	}else if(root->data == "-"){
		return left-right;
	}else if(root->data == "*"){
		return left*right;
	}else if(root->data == "/"){
		return left/right;
	}
}