// Link: https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

// Approach: [TC: O(1) / SC: O(1)]

void MyStack ::push(int x) 
{
    StackNode* temp = new StackNode(x);
    if(!top) top=temp;
    else {
        temp->next = top;
        top=temp;
    }
}

int MyStack ::pop() 
{
    if(!top) return -1;
    else{
        int val = top->data;
        delete top;
        top=top->next;
        return val;
    }
}