// Link: https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1

// Approach: [TC: O(1) / SC: O(1)]

// Function to push an integer into the stack
void MyStack :: push(int x)
{
    top++;
    arr[top]=x;
    return;
}

// Function to remove an item from top of the stack
int MyStack :: pop()
{
    if(top>=0) return arr[top--];
    else return -1;
}