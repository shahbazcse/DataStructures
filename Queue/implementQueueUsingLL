// Link: https://practice.geeksforgeeks.org/problems/implement-queue-using-linked-list/1

// Approach: [TC: O(1) / SC: O(1)]

void MyQueue:: push(int x)
{
    if(!front && !rear){
        QueueNode* temp = new QueueNode(x);
        front = temp;
        rear = temp;
    }else{
        QueueNode* temp = new QueueNode(x);
        rear->next = temp;
        rear = rear->next;
    }
}

int MyQueue :: pop()
{
    if(!front && !rear) return -1;
    else{
        if(front == rear) rear=rear->next;
        QueueNode* next = front->next;
        int val = front->data;
        front->next = NULL;
        delete front;
        front = next;
        return val;
    }
}