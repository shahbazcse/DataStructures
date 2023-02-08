// Link: https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450

// Approach: Using Stack [TC: O(N) / SC: O(N)]

#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    stack<int> st;

    int k = q.size()/2;

    // store first half of queue into stack
    int cnt=0;
    while(cnt<k){
        st.push(q.front());
        q.pop(); // pop first half from queue
        cnt++;
    }

    // push all elements from stack to the rear of queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    // move first half of queue to the rear of queue
    cnt=0;
    while(cnt<k){
        q.push(q.front());
        q.pop();
        cnt++;
    }

    // again store first half of queue into stack
    cnt=0;
    while(cnt<k){
        st.push(q.front());
        q.pop(); // pop first half from queue
        cnt++;
    }

    // now push elements alternatively first from stack and then from front of queue, to the rear of queue
    while(!st.empty()){
        // push from stack
        q.push(st.top());
        st.pop();

        // push from queue
        q.push(q.front());
        q.pop();
    }
}