// Link: https://www.geeksforgeeks.org/sorted-order-printing-of-an-array-that-represents-a-bst/

// Approach: Recursion [TC: O(N) / SC: O(Height)]

#include <bits/stdc++.h>
using namespace std;

void printSorted(vector<int> levelOrderBST, int idx){
    if(idx>= levelOrderBST.size()) return;
    
    // recursive call for left subtree
    printSorted(levelOrderBST,idx*2+1);

    // print current node
    cout<<levelOrderBST[idx]<<" ";

    // recursive call for right subtree
    printSorted(levelOrderBST,idx*2+2);
}

int main() {
    vector<int> levelOrderBST = {4, 2, 5, 1, 3};
    printSorted(levelOrderBST,0);
    return 0;
}