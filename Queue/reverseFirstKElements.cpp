// Link: https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

// Approach: [TC: O(N) / SC: O(K)]

queue<int> modifyQueue(queue<int> q, int k) {
    deque<int> dq;
    
    int l=q.size()-k;
    
    while(k--){
        int num = q.front();
        q.pop();
        dq.push_front(num);
    }
    
    while(!dq.empty()){
        int num = dq.front();
        dq.pop_front();
        q.push(num);
    }
    
    while(l--){
        int num  = q.front();
        q.pop();
        q.push(num);
    }

    return q;
}