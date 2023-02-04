// Link: https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166

// Approach: Recursion + Backtracking [TC: O(N) / Aux. SC: O(N)]

#include <bits/stdc++.h> 
using namespace std;

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    if(myStack.empty()){
        myStack.push(x);
        return myStack;
    }

    int num = myStack.top();
    myStack.pop();

    pushAtBottom(myStack,x);

    myStack.push(num);
    
    return myStack;
}