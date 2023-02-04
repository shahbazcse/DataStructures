// Link: https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1

// Approach: Recursion [TC: O(N) / Aux. SC: O(N)]

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void solve(stack<int>&s, int cnt, int size){
        if(cnt==size/2){
            s.pop();
            return;
        }
        
        int n=s.top();
        s.pop();
        solve(s,cnt+1,size);
        s.push(n);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int cnt=0;
        solve(s,cnt,sizeOfStack);
    }
};