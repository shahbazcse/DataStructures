// Link: https://practice.geeksforgeeks.org/problems/implement-queue-using-array/1

// Approach: [TC: O(1) / SC: O(1)]

void MyQueue :: push(int x)
{
    arr[rear] = x;
    rear++;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
    if(front==rear) return -1;
    int val = arr[front];
    front++;
    return val;
}