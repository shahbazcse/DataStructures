// Link: https://practice.geeksforgeeks.org/problems/handshakes1303/1

// Approach: Recursion [TC: O(2^N) / SC: O(1)]

class Solution{
public:
    // This code calculates the total number of possible handshakes between N people. It uses a recursive approach, where the count of each possible handshake is calculated by multiplying the count of the previous handshake variations. The base case is when N is 0, in which case the count is returned as 1 to keep the total count unchanged.
int count(int N){
        if(N==0) return 1; // for count(0) return 1 to keep the total count unchanged
        
        // calculate count of each possible handshake
        int cnt = 0;
        for(int i = 0; i<N; i+=2){
            // recursive calls return returning and adding count from previous handshake variations
            cnt += count(i) * count(N-2-i);
        }
        return cnt;
    }
};