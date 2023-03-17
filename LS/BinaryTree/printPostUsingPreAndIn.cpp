// Link: https://practice.geeksforgeeks.org/problems/postorder-traversal-from-given-inorder-and-preorder-traversals/1

// Approach 1: Recursion [TC: O(N^2) / SC: O(N)]

int search(int arr[], int x, int n) 
{ 
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1; 
} 
void printPostOrder(int in[], int pre[], int n)
{
    // The first element in pre[] is always root, search it 
    // in in[] to find left and right subtrees 
    int root = search(in, pre[0], n);
    
    // If left subtree is not empty, print left subtree 
    if (root != 0) 
     printPostOrder(in, pre + 1, root);
    
    // If right subtree is not empty, print right subtree 
    if (root != n - 1) 
     printPostOrder(in + root + 1, pre + root + 1, n - root - 1);
    
    // Print root 
    cout << pre[0] << " "; 
}

// Approach 2: Recursion + Map [TC: O(N) / SC: O(N)]

void print(int pre[], int &preStart, int in[], int inStart, int inEnd, unordered_map<int,int> &inMap){
    if(inStart > inEnd) return;

    // Starting node of preorder will be root, use node value to search on map and find root index in inorder
    int rootIdx = inMap[pre[preStart++]]; // increment preStart by 1 to get next root node in next recursive call

    // make recursive call for left subtree
    print(pre,preStart,in,inStart,rootIdx-1,inMap);

    // make recursive call for right subtree
    print(pre,preStart,in,rootIdx+1,inEnd,inMap);

    // print root node at the end (postorder traversal)
    cout<<in[rootIdx]<<" ";
}

void printPostOrder(int in[], int pre[], int n)
{
    // mapping inorder traversal
    unordered_map<int,int> inMap;

    for(int i=0; i<n; i++){
        inMap[in[i]] = i;
    }

    // starting of preorder will always have root node of each subtree
    int preStart = 0;

    print(pre, preStart, in, 0, n-1, inMap);
}