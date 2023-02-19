// Link: https://practice.geeksforgeeks.org/problems/sort-a-stack/1

// Approach: Recursion [TC: O(N^2) / Aux. SC: O(N)]

/*
    The function checks if the stack is empty or if the top element of the stack is less than the given integer.
    If either of these conditions are true, the given integer is pushed onto the stack.
    If neither of these conditions are true, the top element of the stack is stored in a variable and then popped off the stack.
    The helper function is then called recursively with the given integer as a parameter.
    Finally, the stored element is pushed back onto the stack.
    This function is used to sort a stack of integers in ascending order.

*/
void helper(stack<int> &s, int num){
    if(s.empty() || s.top()<num){
        s.push(num);
        return;
    }
    
    int n = s.top();
    s.pop();
    
    helper(s,num);
    
    s.push(n);
}

/*
    The function first checks if the stack is empty, and if it is, it returns.
    If the stack is not empty, the top element is stored in the variable num, and then popped off the stack.
    The sort() function is then called recursively, and the helper() function is called with the stack and the num variable as parameters.
    The helper() function is responsible for inserting the num variable back into the stack in the correct sorted order.
*/
void SortedStack :: sort()
{
    if(s.empty()) return;
    
    int num = s.top();
    s.pop();
    
    sort();
    
    helper(s,num);
}