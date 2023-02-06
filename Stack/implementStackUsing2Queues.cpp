// Link: https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1

// Approach: [TC: push: O(1) & pop: O(N) / SC: O(1)]

void QueueStack :: push(int x)
{
    q1.push(x);
}

int QueueStack :: pop()
{
    if(q1.empty()) return -1;
    else{
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return val;
    }
}