// Link: https://practice.geeksforgeeks.org/problems/queue-reversal/1

// Approach: Recursion + Backtracking [TC: O(N) / SC: O(N)]

void helper(queue<int> &q){
    if(q.empty()) return;
    
    int num = q.front();
    q.pop();
    
    helper(q);
    
    q.push(num);
}
queue<int> rev(queue<int> q)
{
    helper(q);
    return q;
}