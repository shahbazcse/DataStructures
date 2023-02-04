// Link: https://practice.geeksforgeeks.org/problems/reverse-a-stack/1

// Approach: Recursion + Backtracking [TC: O(N) / Aux. SC: O(N)]

class Solution{
public:
    void insertAtBottom(stack<int>& St, int x){
        // base condition
        if(St.empty()){
            St.push(x);
            return;
        }
    
        int num = St.top();
        St.pop();
        
        // recursive call
        insertAtBottom(St,x);
    
        // backtrack
        St.push(num);
    }
    
    void Reverse(stack<int> &St){
        // base condition
        if(St.empty()) return;
        
        int num = St.top();
        St.pop();
        
        // recursive call
        Reverse(St);
        
        // backtrack
        insertAtBottom(St,num);
    }
};