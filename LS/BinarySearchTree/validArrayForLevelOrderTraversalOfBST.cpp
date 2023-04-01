// Link: https://www.geeksforgeeks.org/check-given-array-can-represent-level-order-traversal-binary-search-tree/

// Approach: Iterative + Queue [TC: O(N) / SC: O(N)]

#include <bits/stdc++.h>
using namespace std;

struct Node{
 // node data
 int data;

 // min and max values to determine whether the next node will lie in the right or left subtree
 int min;
 int max;
};

bool validBST(int arr[], int n){
    if(n==0) return true;
    
    // index to keep track of array elements as nodes
    int i=0;

    // queue to perform level order traversal
    queue<Node> q;
    
    // creating root of BST
    Node curr;
    curr.data = arr[i++];
    curr.min = INT_MIN;
    curr.max = INT_MAX;
    
    q.push(curr);
    
    // traverse until there are no more elements in arr[] or queue is not empty
    while(i<n && !q.empty()){
        Node temp = q.front();
        q.pop();
        
        // check whether the ith element in arr[] can be the left child or current root (temp.data)
        if(i<n && (arr[i] > temp.min && arr[i] < temp.data)){
            curr.data = arr[i++];
            curr.min = temp.min;
            curr.max = temp.data;
            q.push(curr);
        }

        // check whether the ith element in arr[] can be the right child or current root (temp.data)
        if(i<n && (arr[i] < temp.max && arr[i] > temp.data)){
            curr.data = arr[i++];
            curr.min = temp.data;
            curr.max = temp.max;
            q.push(curr);
        }
    }
    // check whether all nodes are part of the valid BST, i.e. all nodes are exhausted, so array will be empty, hence return true
    return (i==n);
}

int main() {
    int arr[] = {11, 6, 13, 5, 12, 10};   
    int n = sizeof(arr) / sizeof(arr[0]);   
    if (validBST(arr, n))
        cout << "Yes";
    else
        cout << "No";       
    return 0;
}