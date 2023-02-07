// Link: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// Approach: [TC: O(N) / SC: O(K)]

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<long long int> dq;
    vector<long long> ans;
    
    // Negative element in first K elements
    for(int i=0; i<K; i++){
        // check negative element
        if(A[i]<0){
            dq.push_back(i);
        }
    }

    // check if negative element exists in deque or not
    if(dq.size() != 0){
        ans.push_back(A[dq.front()]);
    }else{
        ans.push_back(0);
    }
    
    // Negative element in remaining K windows
    for(int i=K; i<N; i++){
        // remove element from front
        if(!dq.empty() && i-dq.front() >= K){
            dq.pop_front();
        }
        
        // check negative element, if found, add to rear side of deque (hence moving to next K window)
        if(A[i]<0){
            dq.push_back(i);
        }
        
        // check if negative element exists in deque or not
        if(dq.size() != 0){
            ans.push_back(A[dq.front()]);
        }else{
            ans.push_back(0);
        }
    }
    // return list containing first negative elements in K sized windows in the array 
    return ans;
}